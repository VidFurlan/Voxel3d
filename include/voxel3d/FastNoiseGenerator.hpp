#ifndef FAST_NOISE_GENERATOR_H
#define FAST_NOISE_GENERATOR_H

#include <algorithm>
#include <vector>

namespace fng {
    template <typename T>

    class NoiseMap {
    public:
        NoiseMap(int width, int height) : width(width), height(height) {
            map.resize(height);
            for (auto &row : map) {
                row.resize(width);
            }
        }

        NoiseMap(int width, int height, double defaultValue) : width(width), height(height) {
            map.resize(height);
            for (auto &row : map) {
                row.resize(width);
                std::fill(row.begin(), row.end(), defaultValue);
            }
        }

        NoiseMap operator+(const NoiseMap<T> obj) {
            NoiseMap newMap = NoiseMap(std::max(width, obj.width), std::max(height, obj.width), 0);
            for (int r = 0; r < height; r++)
                for (int c = 0; c < width; c++)
                    newMap[r][c] += map[r][c];

            for (int r = 0; r < obj.height; r++)
                for (int c = 0; c < obj.width; c++)
                    newMap[r][c] += obj[r][c];

            return newMap;
        }

        std::vector<T>& operator[](int index) {
            return map[index];
        }

        const std::vector<T>& operator[](int index) const {
            return map[index];
        }

        int mapWidth() {
            return width;
        }

        int mapHeight() {
            return height;
        }

        void SetMap() {
            for (auto &row : map) {
                std::fill(row.begin(), row.end(), 0);
            }
        }

        void SetMap(T value) {
            for (auto &row : map) {
                std::fill(row.begin(), row.end(), value);
            }
        }

    private:
        int width;
        int height;
        std::vector<std::vector<T>> map;
    };
}

#endif
