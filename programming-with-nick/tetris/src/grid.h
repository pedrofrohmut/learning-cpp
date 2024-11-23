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

        std::vector<Color> getCellColors();

    public:
        Grid(void);
        ~Grid(void);
        void initialize(void);
        void printGrid(void);
        void draw(void);
        int getHeight();
        int getWidth();
};
