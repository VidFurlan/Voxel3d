#ifndef CHUNK_LOADER_H
#define CHUNK_LOADER_H

#include <vector>

#include "Chunk.hpp"
#include "ChunkRenderer.hpp"

class ChunkLoader {
    private:
        std::vector<Chunk *> chunks;
        std::vector<Chunk *> visibleChunks;

    public:
        ChunkLoader();

        int getBlock();
        int setBlock();
        int setGeneratedBlock();

        void updateChunks();
        void drawChunks();

        void saveData();
        void loadData();
};
#endif
