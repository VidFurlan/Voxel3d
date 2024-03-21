#ifndef CHUNK_RENDERER_H
#define CHUNK_RENDERER_H

#include <glm/glm.hpp>
#include <glm/fwd.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Chunk.hpp"
#include "WorldUtil.hpp"

class ChunkRenderer {
    private:
        Chunk *chunk;
        bool visibleFacePosX [CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];
        bool visibleFaceNegX [CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];
        bool visibleFacePosY [CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];
        bool visibleFaceNegY [CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];
        bool visibleFacePosZ [CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];
        bool visibleFaceNegZ [CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];

    public:
        ChunkRenderer(Chunk *chunkToRender);

        void UpdateFacesAtChunkMash();
        void UpdateAllFacesChunkMash();
        void UpdateDirectionalChunkMash();
        void RenderChunk();

};
#endif
