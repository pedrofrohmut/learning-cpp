#include "globals.h"
#include "grid.h"
#include "blocks.cpp"

#include "raylib.h"

int main(void)
{
    Grid grid = Grid();
    grid.initialize();
    grid.printGrid();

    /*grid.setCell(1, 3, 5);*/
    /*grid.setCell(1, 4, 5);*/
    /*grid.setCell(1, 5, 5);*/
    /*grid.setCell(2, 4, 5);*/

    /*LBlock l = LBlock();*/
    /*TBlock t = TBlock();*/

    InitWindow(grid.getWidth(), grid.getHeight(), "Hello, World!");
    SetTargetFPS(30);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(clrDarkBlue);
        grid.draw();
        /*l.draw();*/
        /*t.draw();*/
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
