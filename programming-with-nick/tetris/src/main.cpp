#include "globals.h"

#include "raylib.h"

#include "grid.h"

int main(void)
{
    Grid grid = Grid();
    grid.initialize();
    grid.printGrid();

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
