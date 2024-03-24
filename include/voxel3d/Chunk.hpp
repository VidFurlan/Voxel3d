#ifndef CHUNK_H
#define CHUNK_H

#include "WorldUtil.hpp"

class Chunk {
    private:
        // General chunk data
        int x, y, z;
        int chunkData[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];

        Chunk *neighbors[6];

        // Chunk mesh
        bool visibleFacesPosX[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];
        bool visibleFacesNegX[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];
        bool visibleFacesPosY[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];
        bool visibleFacesNegY[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];
        bool visibleFacesPosZ[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];
        bool visibleFacesNegZ[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];

    public:
        Chunk(int x, int y, int z);

        void generateChunk();
        void updateChunk();
        void loadChunk();

        void updateFacesAtChunkMash();
        void updateAllFacesChunkMash();
        void updateDirectionalChunkMash();
        void renderChunk();

        int getBlock(int x, int y, int z);

        int setNeigbor(Chunk *chunk, int index);
};
#endif
