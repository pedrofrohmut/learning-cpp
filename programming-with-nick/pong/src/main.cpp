#include <raylib.h>

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Hello, World! - Raylib Example");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Update
        // TODO: Update your game logic here

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Hello, World!", screenWidth / 2 - MeasureText("Hello, World!", 20) / 2, screenHeight / 2 - 10, 20, LIGHTGRAY);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
