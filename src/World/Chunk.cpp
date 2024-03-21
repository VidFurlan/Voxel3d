#include "Chunk.hpp"
Chunk::Chunk() {
    chunkData = std::vector<std::vector<std::vector<int>>>(32, std::vector<std::vector<int>>(32, std::vector<int>(32, 1)));
}

void Chunk::Update() {
}
