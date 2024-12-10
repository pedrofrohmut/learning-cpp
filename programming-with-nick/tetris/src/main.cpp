#include "globals.h"
#include "grid.h"

#include "raylib.h"

int main(void)
{
    Grid grid = Grid();
    grid.initialize();
    grid.printGrid();

    grid.setCell(1, 3, 5);
    grid.setCell(1, 4, 5);
    grid.setCell(1, 5, 5);
    grid.setCell(2, 4, 5);

    InitWindow(grid.getWidth(), grid.getHeight(), "Hello, World!");
    SetTargetFPS(30);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(clrDarkBlue);
        grid.draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
