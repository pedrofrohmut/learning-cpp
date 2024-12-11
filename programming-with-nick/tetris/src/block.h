#pragma once

#include "globals.h"

#include <vector>
#include <map>

#include "position.h"

class Block
{
private:
    int cellSize;
    int rotationState;

public:
    int id;
    std::map<int, std::vector<Position>> cells;
    std::vector<Color> colors;

    Block(void);
    void draw(void);
};
