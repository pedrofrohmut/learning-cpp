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
            const size_t posX = j * this->cellSize;
            const size_t posY = i * this->cellSize;
            const size_t cellValue = this->grid[i][j];
            const Color cellColor = this->colors[cellValue];
            DrawRectangle(posX, posY, this->cellSize, this->cellSize, cellColor);
        }
    }

    // Draw Vertical Lines
    for (int i = 1; i < this->numCols; ++i) {
        const int x = i * this->cellSize;
        const int endY = this->numRows * this->cellSize;
        DrawLine(x, 0, x, endY, WHITE);
    }

    // Draw Horizontal Lines
    for (int i = 1; i < this->numRows; ++i) {
        const int y = i * this->cellSize;
        const int endX = this->numCols * cellSize;
        DrawLine(0, y, endX, y, WHITE);
    }
}

int Grid::getHeight()
{
    return this->numRows * this->cellSize;
}

int Grid::getWidth()
{
    return this->numCols * this->cellSize;
}
