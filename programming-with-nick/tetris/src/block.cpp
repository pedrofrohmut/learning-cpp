#include "block.h"

Block::Block(void)
{
    this->cellSize = 30;
    this->rotationState = 0;
    this->colors = getCellColors();
}

void Block::draw(void)
{
    std::vector<Position> tiles = cells[rotationState];
    const int size = this->cellSize;
    const int id = this->id;
    for (auto& tile : tiles) {
        const int posX = (tile.col * size) + 1;
        const int posY = (tile.row * size) + 1;
        const int width = size - 1;
        const int height = width;
        const Color color = colors[id];
        DrawRectangle(posX, posY, width, height, color);
    }
}
