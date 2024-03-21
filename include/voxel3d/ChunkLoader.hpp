#ifndef CHUNK_LOADER_H
#define CHUNK_LOADER_H

#include <vector>

#include "Chunk.hpp"

class ChunkLoader {
    private:
        std::vector<Chunk *> chunks;

    public:
        int getBlock();
        int setBlock();
        int setGeneratedBlock();

        void draw();

        void saveData();
        void loadData();
};
#endif
