#ifndef WORLD_UTIL_H
#define WORLD_UTIL_H

const int CHUNK_SIZE = 32;

const int AIR_BLOCK = 0;
const int WATER_BLOCK = 1;

const float VOXEL_VERTICES[5*6*6] = {
    -0.5f, -0.5f, -0.5f,      0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,      1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,      1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,      1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,      0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,      0.0f, 0.0f,


    -0.5f, -0.5f,  0.5f,      0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,      1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,      1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,      1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,      0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,      0.0f, 0.0f,


    -0.5f,  0.5f,  0.5f,      1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,      1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,      0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,      0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,      0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,      1.0f, 0.0f,


    0.5f,  0.5f,  0.5f,      1.0f, 0.0f,
    0.5f,  0.5f, -0.5f,      1.0f, 1.0f,
    0.5f, -0.5f, -0.5f,      0.0f, 1.0f,
    0.5f, -0.5f, -0.5f,      0.0f, 1.0f,
    0.5f, -0.5f,  0.5f,      0.0f, 0.0f,
    0.5f,  0.5f,  0.5f,      1.0f, 0.0f,


    -0.5f, -0.5f, -0.5f,      0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,      1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,      1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,      1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,      0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,      0.0f, 1.0f,


    -0.5f,  0.5f, -0.5f,      0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,      1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,      1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,      1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,      0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,      0.0f, 1.0f
};

bool isBlockTrasnparent(int block);

#endif