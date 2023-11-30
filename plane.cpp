
#include "plane.h"
#include "primitives.h"
#include "materials.h"

Plane::Plane() {}

void Plane::create() {

	Primitives primitive;

    float vertices[4][3] = {
        { 0.5f, 0.0f,-0.5f},
        {-0.5f, 0.0f,-0.5f},
        {-0.5f, 0.0f, 0.5f},
        { 0.5f, 0.0f, 0.5f}
    };

    Materials material;
    material.apply(material.white, &material.white[4], &material.white[8], material.white[12]);

	primitive.surface4(vertices[3], vertices[2], vertices[1], vertices[0]);

}