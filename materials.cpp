
#include <GL/glut.h>
#include "materials.h"

Materials::Materials() {

}

void Materials::apply(float ambient[], float diffuse[], float specular[], float shininess) {

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

}