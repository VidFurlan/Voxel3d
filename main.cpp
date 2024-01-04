#include <GL/freeglut_std.h>
#include <cstdlib>
#include <stdlib.h>

// OpenGL
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/gl.h>
#endif

using namespace std;

void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            exit(0);
    }
}

void initRendering() {
    glEnable(GL_DEPTH_TEST);
}

void handleResize(int w, int h) {
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluPerspective(45.0,                    // Cam angle
                   (double)w / (double)h,   // Width height ratio
                   1.0,                     // Near Z clipping coordinate
                   200.0);                  // Far Z clipping coordinate
}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_QUADS);

    glVertex3f(-0.5f, -1.0f, -5.0f);
    glVertex3f(0.5f , -1.0f, -5.0f);
    glVertex3f(0.5f , 0.0f,  -5.0f);
    glVertex3f(-0.5f, 0.0f,  -5.0f);
    
    glVertex3f(-0.5f, 0.0f,  -5.0f);
    glVertex3f(0.5f , 0.0f,  -5.0f);
    glVertex3f(0.5f , 0.3f,  -6.0f);
    glVertex3f(-0.5f, 0.3f,  -6.0f);
    
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    // Init GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);

    glutCreateWindow("Voxel 3D");
    initRendering(); 

    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutReshapeFunc(handleResize);

    glutMainLoop();

    return 0;
}
