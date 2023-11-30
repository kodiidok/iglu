
#include "primitives.h"
#include "materials.h"
#include <GL/glut.h>
#include <math.h>

Primitives::Primitives() {

}

void Primitives::surface4(float* v1, float* v2, float* v3, float* v4) {

    float* normal = calculateNormals(v4, v1, v3);
    
    glNormal3fv(&normal[0]);

    Materials material;
    material.apply(material.white, &material.white[4], &material.white[8], material.white[12]);

    glBegin(GL_POLYGON);
        glVertex3fv(v4);
        glVertex3fv(v3);
        glVertex3fv(v2);
        glVertex3fv(v1);
    glEnd();

}

float* Primitives::calculateNormals(float* v1, float* v2, float* v3) {

    GLfloat u[3] = { v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2] };
    GLfloat v[3] = { v3[0] - v1[0], v3[1] - v1[1], v3[2] - v1[2] };

    // Calculate the cross product
    GLfloat normal[3] = {
        u[1] * v[2] - u[2] * v[1],
        u[2] * v[0] - u[0] * v[2],
        u[0] * v[1] - u[1] * v[0]
    };

    // Normalize the normal vector
    GLfloat length = sqrt(normal[0] * normal[0] + normal[1] * normal[1] + normal[2] * normal[2]);
    normal[0] /= length;
    normal[1] /= length;
    normal[2] /= length;

    // Return the normal vector
    return normal;
}