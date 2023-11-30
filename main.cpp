
#include <iostream>
#include <GL/glut.h>
#include <math.h>

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

int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);

void init() {

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

}

void loadObjects() {
    
    Plane plane;
    Cube cube;

    glPushMatrix();
        glScalef(5.0f, 5.0f, 5.0f);
        plane.create();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0f, 0.5f, 0.0f);
        cube.create();
    glPopMatrix();

}

void viewportLights() {

    glEnable(GL_LIGHT0);

    GLfloat light0_position[] = { 2.0f, 2.0f, 2.0f, 2.0f };
    GLfloat light0_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat light0_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light0_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);

}

void camera() {

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

}

void scene() {

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    viewportLights();
    camera();

    glEnable(GL_COLOR_MATERIAL);

    Grid grid;
    //grid.create(20, 20);

    glDisable(GL_COLOR_MATERIAL);

    glShadeModel(GL_SMOOTH);

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

void keyboardSpecial(int key, int x, int y) {

    switch (key)
    {
    default:
        break;
    }

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
    case 'f': //toggle screenmode
        if (glutGetModifiers() == GLUT_ACTIVE_ALT) {
            glutFullScreen();
        }
        break;
    case 27: // ASCII code for the Escape key
        glutReshapeWindow(screenWidth / 2, screenHeight / 2);
        glutPositionWindow(100, 100);
        break;
    }

    glutPostRedisplay();
}

void instructions() {

    std::cout << "Welcome to Rubik's Cube Engine!\n--------------------------------\n" << std::endl;

    std::cout << "Controls\n" << std::endl;

    std::cout << "ALT + F\t\tToggle On Fullscreen" << std::endl;
    std::cout << "ESC\t\tToggle Off Fullescreen" << std::endl;

}

int main(int argc, char** argv) {

    instructions();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);

    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Window");
    glutFullScreen();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    init();

    glutMainLoop();

    return 0;

}