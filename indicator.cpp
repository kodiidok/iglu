
#include "indicator.h"
#include <GL/glut.h>

Indicator::Indicator() {

}

void Indicator::create() {

	glColor3f(1.0f, 1.0f, 1.0f);

	glPushMatrix();

	glTranslatef(3.0f, 3.0f, 0.0f);
	glutSolidCube(1);

	glPopMatrix();

}

void Indicator::rotate(float rotX, float rotY, float rotZ) {

	glRotatef(rotX, 1.0f, 0.0f, 0.0f);
	glRotatef(rotY, 0.0f, 1.0f, 0.0f);
	glRotatef(rotZ, 0.0f, 0.0f, 1.0f);

}
