
#ifndef PRIMITIVES_H
#define PRIMITIVES_H

class Primitives {
public:
	Primitives();
	void surface4(float* v1, float* v2, float* v3, float* v4);
	float* calculateNormals(float* v1, float* v2, float* v3);
};

#endif