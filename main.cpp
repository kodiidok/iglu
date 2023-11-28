
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#include "models.h"

// Global

GLfloat posX = 0.0f;
GLfloat posY = 0.0f;
GLfloat posZ = 0.0f;

GLfloat rotX = 0.0f;
GLfloat rotY = 0.0f;
GLfloat rotZ = 0.0f;

GLfloat camX = 0.0f;
GLfloat camY = 0.0f;
GLfloat camZ = 0.0f;

void init() {

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1);
    glEnable(GL_DEPTH_TEST);

}

void loadObjects() {

    
}

void scene() {

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(
        3.0, 3.0, 3.0,  // Eye position
        0.0, 0.0, 0.0,  // Look-at position
        0.0, 1.0, 0.0   // Up vector
    );

    // Apply rotation to the scene
    glRotatef(rotX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotY, 0.0f, 1.0f, 0.0f);
    glRotatef(rotZ, 0.0f, 0.0f, 1.0f);

    // Apply translation to the scene
    glTranslatef(posX, posY, posZ);

    Grid grid;
    grid.create(20, 20);

    loadObjects();

}

void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    scene();
    
    glutSwapBuffers();

}

void reshape(GLsizei w, GLsizei h) {

    glViewport(0, 0, w, h);

    GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(120.0, aspect_ratio, 1.0, 100.0);
}

void keyboard(unsigned char key, int x, int y) {

    switch (key) {
    case 'x': // Move along X-axis in the positive direction
        posX += 1.0f;
        break;
    case 'X': // Move along X-axis in the negative direction
        posX -= 1.0f;
        break;
    case 'z': // Move along Z-axis in the positive direction
        posZ += 1.0f;
        break;
    case 'Z': // Move along Z-axis in the negative direction
        posZ -= 1.0f;
        break;
    case 'c': // Move along Y-axis in the positive direction
        posY += 1.0f;
        break;
    case 'C': // Move along Y-axis in the negative direction
        posY -= 1.0f;
        break;
    case '8': // Numpad 8: Rotate around X-axis in the positive direction
        rotX += 5.0f;
        break;
    case '2': // Numpad 2: Rotate around X-axis in the negative direction
        rotX -= 5.0f;
        break;
    case '4': // Numpad 4: Rotate around Y-axis in the positive direction
        rotY += 5.0f;
        break;
    case '6': // Numpad 6: Rotate around Y-axis in the negative direction
        rotY -= 5.0f;
        break;
    case '7': // Numpad 7: Rotate around Z-axis in the positive direction
        rotZ += 5.0f;
        break;
    case '9': // Numpad 9: Rotate around Z-axis in the negative direction
        rotZ -= 5.0f;
        break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);

    glutInitWindowSize(720, 480);
    glutInitWindowPosition(300, 150);
    glutCreateWindow("Window");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    init();

    glutMainLoop();

    return 0;

}