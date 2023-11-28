#include "grid.h"
#include <GL/glut.h>

Grid::Grid() {
}

void Grid::create(int x, int z) {
    glColor3f(0.2f, 0.2f, 0.2f);

    // Draw lines along the Z-axis
    glBegin(GL_LINES);
    for (int i = 0; i <= x; ++i) {
        float xPos = i - x / 2.0f;
        glVertex3f(xPos, 0.0f, -z / 2.0f);
        glVertex3f(xPos, 0.0f, z / 2.0f);
    }
    glEnd();

    // Draw lines along the X-axis
    glBegin(GL_LINES);
    for (int i = 0; i <= z; ++i) {
        float zPos = i - z / 2.0f;
        glVertex3f(-x / 2.0f, 0.0f, zPos);
        glVertex3f(x / 2.0f, 0.0f, zPos);
    }
    glEnd();
}
