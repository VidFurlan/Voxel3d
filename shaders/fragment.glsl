#version 330 core
out vec4 FragColor;

in vec2 TexCoord;
uniform sampler2D textureArr;
uniform int cubeData; 

void main()
{
    int x = (cubeData >> 18) & 0x3F;
    int y = (cubeData >> 12) & 0x3F;
    int z = (cubeData >> 6) & 0x3F; 

    vec3 cubePosition = vec3(x - 0.5, y - 0.5, z - 0.5);

	FragColor = texture(textureArr, TexCoord);
}
