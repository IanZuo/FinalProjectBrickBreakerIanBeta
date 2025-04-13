#include "LevelLoader.h"
#include <fstream>
#include <sstream>

std::vector<Brick> LevelLoader::LoadLevel(const std::string& filePath) {
    std::vector<Brick> bricks;
    std::ifstream file(filePath);
    if (!file.is_open()) return bricks;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int col, row, hp;
        if (!(iss >> col >> row >> hp)) continue;

        float x = 60 * col + 10;
        float y = 30 * row + 50;
        bricks.emplace_back(x, y, 60, 20, hp);
    }

    return bricks;
}
