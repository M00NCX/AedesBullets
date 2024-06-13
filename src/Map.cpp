#include "Map.h"

std::string filename = "Fase2.txt";

void Map::loadMap(const std::string& filename) {
    // Open the map file
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening map file: " << filename << std::endl;
        return;
    }

    // Clear the current map
    map.clear();

    // Read the lines from the file and fill the map matrix
    std::string line;
    while (std::getline(file, line)) {
        std::vector<BlockType> row;
        std::istringstream iss(line);
        char blockChar;
        while (iss >> blockChar) {
            BlockType blockType;
            if (blockChar == '0') {
                blockType = BlockType::SOLID;
            } else if (blockChar == '1') {
                    blockType = BlockType::EMPTY;
            } else if (blockChar == '2') {
                    blockType = BlockType::FOCO;
            }
            row.push_back(blockType);
        }
        if (!row.empty()) {
            map.push_back(row);
        }
    }

    // Close the file
    file.close();

    // Check if the map is empty
    if (map.empty() || map[0].empty()) {
        std::cerr << "Error: Empty or invalid map." << std::endl;
        return;
    }

    // Check if all rows have the same length
    size_t rowLength = map[0].size();
    for (const auto& row : map) {
        if (row.size() != rowLength) {
            std::cerr << "Error: Inconsistent row lengths in map." << std::endl;
            map.clear();
            return;
        }
    }

    // Set the map dimensions
    mapWidth = rowLength;
    mapHeight = map.size();
}

bool Map::checkCollisionWithMap(float x, float y) const {
    int mapX = static_cast<int>(x / blockSize);
    int mapY = static_cast<int>(y / blockSize);

    // Check if the coordinates are within the map boundaries
    if (mapX < 0 || mapX >= mapWidth || mapY < 0 || mapY >= mapHeight) {
        return true; // Collision with the map boundaries
    }

    // Check if the block is solid
    return map[mapY][mapX] == BlockType::SOLID;
}

bool Map::checkFocoWithMap(float x, float y) const {
    int mapX = static_cast<int>(x / blockSize);
    int mapY = static_cast<int>(y / blockSize);

    // Check if the coordinates are within the map boundaries
    if (mapX < 0 || mapX >= mapWidth || mapY < 0 || mapY >= mapHeight) {
        return false; // Out of bounds is not a foco
    }

    // Check if the block is a Foco de dengue
    return map[mapY][mapX] == BlockType::FOCO;
}

int Map::getWidth() const {
    return mapWidth * blockSize;
}

int Map::getHeight() const {
    return mapHeight * blockSize;
}

BlockType Map::getBlockType(int x, int y) const {
    if (x >= 0 && x < mapWidth && y >= 0 && y < mapHeight) {
        return map[y][x];
    }
    //return BlockType::EMPTY; // Return EMPTY for out of bounds, could also throw an exception or handle it differently
}

void Map::removeFocoBlock(int x, int y) {
    if (x >= 0 && x < mapWidth && y >= 0 && y < mapHeight) {
        if (map[y][x] == BlockType::FOCO) {
            map[y][x] = BlockType::EMPTY; // Remove block by setting it to EMPTY
                    std::cout << "Foco ELIMINADO!" << std::endl;
        }
    }
}