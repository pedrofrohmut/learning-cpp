#pragma once

#include "raylib.h"
#include <vector>

#define GRID_ROWS 20
#define GRID_COLS 20

class Grid
{
    private:
        int grid[GRID_ROWS][GRID_COLS];
        int numRows;
        int numCols;
        int cellSize;
        std::vector<Color> colors;

    public:
        Grid(void);
        ~Grid(void);
        void initialize(void);
        void printGrid(void);
        void draw(void);
        int getHeight(void);
        int getWidth(void);
        void setCell(size_t row, size_t col, int colorCode);
};
