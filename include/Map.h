#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// Enum to represent the types of blocks in the map
enum class BlockType {
    SOLID,
    EMPTY
};

class Map {
public:
    // Method to load a map from a file
    void loadMap(const std::string& filename);

    // Method to check for collision with the map
    bool checkCollisionWithMap(float x, float y) const;

    // Get the width of the map in blocks
    int getWidth() const;

    // Get the height of the map in blocks
    int getHeight() const;

    // Get the block type at a specific position
    BlockType getBlockType(int x, int y) const;

private:
    // 2D vector to store the map
    std::vector<std::vector<BlockType>> map;

    // Map dimensions in terms of number of blocks
    int mapWidth = 0;
    int mapHeight = 0;

    // Size of each block (assumed to be a square)
    static constexpr int blockSize = 5; // Adjust this size as needed
};

#endif // MAP_H