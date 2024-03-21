#ifndef CHUNK_H
#define CHUNK_H

#include <vector>

class Chunk {
    private:
        int x, y, z;
        int chunkData[32][32][32];
        
        Chunk *neighbors[6];

    public:
        Chunk(int x, int y, int z);

        void generateChunk();
        void updateChunk();
        void loadChunk();

        int getBlock(int x, int y, int z);

        int setBeigbor(Chunk *chunk, int index);
};
#endif
