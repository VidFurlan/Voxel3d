#include "Chunk.hpp"
Chunk::Chunk(int xCord, int yCord, int zCord) : x(xCord), y(yCord), z(zCord) {

}

void Chunk::renderChunk() {
    for (int x = 0; x < CHUNK_SIZE; x++) {
        for (int y = 0; y < CHUNK_SIZE; y++) {
            for (int z = 0; z < CHUNK_SIZE; z++) {
                if (x - 1 > 0 && isBlockTrasnparent(this->getBlock(x - 1, y, z))) {

                }
            }
        }
    }
}
