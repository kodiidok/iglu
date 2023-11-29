
#ifndef MATERIALS_H
#define MATERIALS_H

class Materials
{
public:
	Materials();
    void apply(float ambient[], float diffuse[], float specular[], float shininess);

    float white[13] = {
        1.0, 1.0, 1.0, 1.0,      // ambient
        1.0, 1.0, 1.0, 1.0,      // diffuse
        1.0, 1.0, 1.0, 1.0,      // specular
        50.0                     // shininess
    };

    float red[13] = {
        0.8, 0.1, 0.1, 1.0,      // ambient
        0.8, 0.1, 0.1, 1.0,      // diffuse
        0.8, 0.1, 0.1, 1.0,      // specular
        50.0                     // shininess
    };

    float blue[13] = {
        0.1, 0.1, 0.8, 1.0,      // ambient
        0.1, 0.1, 0.8, 1.0,      // diffuse
        0.1, 0.1, 0.8, 1.0,      // specular
        50.0                     // shininess
    };

};

#endif // !MATERIALS_H
