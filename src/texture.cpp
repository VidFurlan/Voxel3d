#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

GLuint loadBMP (const char* imagepath) {
    printf("Reading BMP image %s\n", imagepath);

    // Read header of BMP file
    unsigned char header[54];
    unsigned int data_pos;
    unsigned int image_size;
    unsigned int width, height;
    unsigned char* data;

    // Open file
    FILE* file = fopen(imagepath, "rb");
    if (!file) {
        printf("%s could not be opened", imagepath);
        getchar();
        return 0;
    }

    // If less then 54 bytes read (header file is 54 bytes)
    if (fread(header, 1, 54, file) != 54) {
        printf("Not a valid BMP file!\n");
        fclose(file);
        return 0;
    }

    // File should begin with "BM"
    if (header[0] != 'B' || header[1] != 'M') {
        printf("Not a valid BMP file! (Doesn't start with BM')\n");
        fclose(file);
        return 0;
    }

    // Vertify that the file is 24bpp
    /*if (*(int*) &(header[0x0A]) != 0 || *(int*) &(header[0x0A]) != 0) {
        printf("Not a valid BMP file! (Not 24bpp)\n");
        fclose(file);
        return 0;
    }*/

    // Read image data
    data_pos    = *(int*) &(header[0x0A]);
    image_size  = *(int*) &(header[0x22]);
    width       = *(int*) &(header[0x12]);
    height      = *(int*) &(header[0x16]);

    // If file has missing data
    if (!image_size) image_size=width*height*3; // 3 - one byte for each R G B
    if (!data_pos)   data_pos=54; // BMP header file size

    // Create and read to buffer 
    data = new unsigned char [image_size];
    fread(data, 1, image_size, file);
    fclose(file);

    // Create OpenGL texture
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
    
    // Free data
    delete [] data;

    // Filtering and minmaps
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);

    return textureID;
}

GLuint loadTGA_glfw(const char* imagepath) {
    // Create OpenGL texture
    GLuint textureID;
    glGenTextures(1, &textureID);

    glBindTexture(GL_TEXTURE_2D, textureID);

    // Load TGA image using STB image
    int width, height, numChannels;
    unsigned char* data = stbi_load(imagepath, &width, &height, &numChannels, 0);

    if (data) {
        // Upload the image data to OpenGL
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

        // Set texture parameters 
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glGenerateMipmap(GL_TEXTURE_2D);

        // Cleanup STB Image data
        stbi_image_free(data);
    } 
    else {
        // Error handling for texture loading failure
        // You can implement your own error handling logic here
    }

    // Return the ID of the texture we just created
    return textureID;
}


#define FOURCC_DXT1 0x31545844 // Equivalent to "DXT1" in ASCII
#define FOURCC_DXT3 0x33545844 // Equivalent to "DXT3" in ASCII
#define FOURCC_DXT5 0x35545844 // Equivalent to "DXT5" in ASCII

GLuint loadDDS(const char * imagepath){

	unsigned char header[124];

	FILE *fp; 
 
	/* try to open the file */ 
	fp = fopen(imagepath, "rb"); 
	if (fp == NULL){
		printf("%s could not be opened. Are you in the right directory ? Don't forget to read the FAQ !\n", imagepath); getchar(); 
		return 0;
	}
   
	/* verify the type of file */ 
	char filecode[4]; 
	fread(filecode, 1, 4, fp); 
	if (strncmp(filecode, "DDS ", 4) != 0) { 
		fclose(fp); 
		return 0; 
	}
	
	/* get the surface desc */ 
	fread(&header, 124, 1, fp); 

	unsigned int height      = *(unsigned int*)&(header[8 ]);
	unsigned int width	     = *(unsigned int*)&(header[12]);
	unsigned int linearSize	 = *(unsigned int*)&(header[16]);
	unsigned int mipMapCount = *(unsigned int*)&(header[24]);
	unsigned int fourCC      = *(unsigned int*)&(header[80]);

 
	unsigned char * buffer;
	unsigned int bufsize;
	/* how big is it going to be including all mipmaps? */ 
	bufsize = mipMapCount > 1 ? linearSize * 2 : linearSize; 
	buffer = (unsigned char*)malloc(bufsize * sizeof(unsigned char)); 
	fread(buffer, 1, bufsize, fp); 
	/* close the file pointer */ 
	fclose(fp);

	unsigned int components  = (fourCC == FOURCC_DXT1) ? 3 : 4; 
	unsigned int format;
	switch(fourCC) 
	{ 
	case FOURCC_DXT1: 
		format = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT; 
		break; 
	case FOURCC_DXT3: 
		format = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT; 
		break; 
	case FOURCC_DXT5: 
		format = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT; 
		break; 
	default: 
		free(buffer); 
		return 0; 
	}

	// Create one OpenGL texture
	GLuint textureID;
	glGenTextures(1, &textureID);

	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);	
	
	unsigned int blockSize = (format == GL_COMPRESSED_RGBA_S3TC_DXT1_EXT) ? 8 : 16; 
	unsigned int offset = 0;

	/* load the mipmaps */ 
	for (unsigned int level = 0; level < mipMapCount && (width || height); ++level) 
	{ 
		unsigned int size = ((width+3)/4)*((height+3)/4)*blockSize; 
		glCompressedTexImage2D(GL_TEXTURE_2D, level, format, width, height,  
			0, size, buffer + offset); 
	 
		offset += size; 
		width  /= 2; 
		height /= 2; 

		// Deal with Non-Power-Of-Two textures. This code is not included in the webpage to reduce clutter.
		if(width < 1) width = 1;
		if(height < 1) height = 1;

	} 

	free(buffer); 

	return textureID;


}
