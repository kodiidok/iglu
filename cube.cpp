#include "cube.h"
#include "primitives.h"
#include "materials.h"

struct Mesh { 
    float vertices[8][3] = {
        { 0.5f, 0.5f,-0.5f},
        {-0.5f, 0.5f,-0.5f},
        {-0.5f, 0.5f, 0.5f},
        { 0.5f, 0.5f, 0.5f},
        { 0.5f,-0.5f,-0.5f},
        {-0.5f,-0.5f,-0.5f},
        {-0.5f,-0.5f, 0.5f},
        { 0.5f,-0.5f, 0.5f}
    };
};

Cube::Cube() {
    // Constructor
}

void Cube::create() {

    Mesh c;
    Primitives primitive;

    Materials material;
    material.apply(material.white, &material.white[4], &material.white[8], material.white[12]);

    primitive.surface4(c.vertices[0], c.vertices[1], c.vertices[5], c.vertices[4]); // front
    primitive.surface4(c.vertices[3], c.vertices[0], c.vertices[4], c.vertices[7]); // right
    primitive.surface4(c.vertices[2], c.vertices[3], c.vertices[7], c.vertices[6]); // back
    primitive.surface4(c.vertices[2], c.vertices[1], c.vertices[5], c.vertices[6]); // left
    primitive.surface4(c.vertices[4], c.vertices[5], c.vertices[6], c.vertices[7]); // bottom
    primitive.surface4(c.vertices[0], c.vertices[3], c.vertices[2], c.vertices[1]); // top

}
