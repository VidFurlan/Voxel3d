#include "ChunkRenderer.hpp"
#include "WorldUtil.hpp"

ChunkRenderer::ChunkRenderer(Chunk *chunkToRender) : chunk(chunkToRender) {

}

void ChunkRenderer::UpdateAllFacesChunkMash() {
    for (int x = 0; x < CHUNK_SIZE; x++) {
        for (int y = 0; y < CHUNK_SIZE; y++) {
            for (int z = 0; z < CHUNK_SIZE; z++) {
                // TODO: ADD NEIGHBOUR CHUNK CHECK
                visibleFaceNegX[x][y][z] = !(x - 1 > 0 && isBlockTrasnparent(chunk->getBlock(x - 1, y, z)));
                visibleFaceNegX[x][y][z] = !(x + 1 < CHUNK_SIZE && isBlockTrasnparent(chunk->getBlock(x + 1, y, z)));
                visibleFaceNegY[x][y][z] = !(y - 1 > 0 && isBlockTrasnparent(chunk->getBlock(x, y - 1, z)));
                visibleFaceNegY[x][y][z] = !(y + 1 < CHUNK_SIZE && isBlockTrasnparent(chunk->getBlock(x, y + 1, z)));
                visibleFaceNegZ[x][y][z] = !(z - 1 > 0 && isBlockTrasnparent(chunk->getBlock(x, y, z - 1)));
                visibleFaceNegZ[x][y][z] = !(z + 1 < CHUNK_SIZE && isBlockTrasnparent(chunk->getBlock(x, y, z + 1)));
            }
        }
    }
}

void ChunkRenderer::RenderChunk() {
    for (int x = 0; x < CHUNK_SIZE; x++) {
        for (int y = 0; y < CHUNK_SIZE; y++) {
            for (int z = 0; z < CHUNK_SIZE; z++) {
                if (x - 1 > 0 && isBlockTrasnparent(chunk->getBlock(x - 1, y, z))) {

                }

                if (x + 1 < CHUNK_SIZE && isBlockTrasnparent(chunk->getBlock(x + 1, y, z))) {

                }
                
                if (y - 1 > 0 && isBlockTrasnparent(chunk->getBlock(x, y - 1, z))) {

                }
                
                if (y + 1 < CHUNK_SIZE && isBlockTrasnparent(chunk->getBlock(x, y + 1, z))) {

                }
                
                if (z - 1 > 0 && isBlockTrasnparent(chunk->getBlock(x, y, z - 1))) {

                }
                
                if (z + 1 < CHUNK_SIZE && isBlockTrasnparent(chunk->getBlock(x, y, z + 1))) {

                }
            }
        }
    }
}
