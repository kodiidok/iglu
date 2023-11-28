
#ifndef GRID_H
#define GRID_H

class Grid {
public:
    Grid();

    // create a grid from -x/2 t0 x/2 and -z/2 to z/2 on the xz plane
    void create(int x, int z);
};

#endif