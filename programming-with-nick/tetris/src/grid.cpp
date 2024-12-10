#include <iostream>

#include "globals.h"
#include "raylib.h"
#include "grid.h"

Grid::Grid(void)
{
    this->numRows = 20;
    this->numCols = 10;
    this->cellSize = 30;
    this->colors = getCellColors();
}

Grid::~Grid(void)
{
    std::cout << "Destructing grid" << std::endl;
}

void Grid::initialize(void)
{
    for (int i = 0; i < this->numRows; i++) {
        for (int j = 0; j < this->numCols; j++) {
            this->grid[i][j] = 0;
        }
    }
}

void Grid::printGrid(void)
{
    for (int i = 0; i < this->numRows; i++) {
        for (int j = 0; j < this->numCols; j++) {
            std::cout << this->grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<Color> Grid::getCellColors()
{
    return {
        gridClrDarkGrey,
        gridClrGreen,
        gridClrRed,
        gridClrOrange,
        gridClrYellow,
        gridClrPurple,
        gridClrCyan,
        gridClrBlue
    };
}

void Grid::draw()
{
    // Draw cells
    for (int i = 0; i < this->numRows; i++) {
        for (int j = 0; j < this->numCols; j++) {
            const int size = this->cellSize;

            // + 1 on position and -1 on size to make a 1px margin
            const int posX = j * size + 1;
            const int posY = i * size + 1;
            const int width = size - 1;
            const int height = width;

            const size_t cellValue = this->grid[i][j];
            const Color cellColor = this->colors[cellValue];

            DrawRectangle(posX, posY, width, height, cellColor);
        }
    }

#if 0
    // Draw Vertical Lines
    for (int i = 1; i < this->numCols; ++i) {
        const int x = i * this->cellSize;
        const int endY = this->numRows * this->cellSize;
        DrawLine(x, 0, x, endY, gridClrGridLines);
    }

    // Draw Horizontal Lines
    for (int i = 1; i < this->numRows; ++i) {
        const int y = i * this->cellSize;
        const int endX = this->numCols * cellSize;
        DrawLine(0, y, endX, y, gridClrGridLines);
    }
#endif
}

int Grid::getHeight()
{
    return this->numRows * this->cellSize;
}

int Grid::getWidth()
{
    return this->numCols * this->cellSize;
}

void Grid::setCell(size_t row, size_t col, int colorCode)
{
    this->grid[row][col] = colorCode;
}
