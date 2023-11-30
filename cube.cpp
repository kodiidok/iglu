#include "cube.h"
#include "primitives.h"

Cube::Cube() {
    // Constructor
}

void Cube::create() {

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

    Primitives primitive;

    primitive.surface4(vertices[0], vertices[1], vertices[5], vertices[4]); // front
    primitive.surface4(vertices[4], vertices[7], vertices[3], vertices[0]); // right
    primitive.surface4(vertices[2], vertices[3], vertices[7], vertices[6]); // back
    primitive.surface4(vertices[1], vertices[2], vertices[6], vertices[5]); // left
    primitive.surface4(vertices[4], vertices[5], vertices[6], vertices[7]); // bottom
    primitive.surface4(vertices[0], vertices[3], vertices[2], vertices[1]); // top

}
