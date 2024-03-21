#include "WorldUtil.hpp"

bool isBlockTrasnparent(int block) {
    if (block == AIR_BLOCK ||
        block == WATER_BLOCK)
        return true;
    return false;
}
