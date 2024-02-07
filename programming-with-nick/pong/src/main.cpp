#include <raylib.h>
#include <iostream>

// Video: https://www.youtube.com/watch?v=VLJlTaFvHo4

class Ball
{
public:
    float x, y;
    float speed_x, speed_y;
    float radius;

    void draw()
    {
        DrawCircle(x, y, radius, ORANGE);
    }

    void update(int win_width, int win_height)
    {
        if (x + radius >= win_width || x - radius <= 0) speed_x *= -1;
        if (y + radius >= win_height || y - radius <= 0) speed_y *= -1;
        x += speed_x;
        y += speed_y;
    }
};

int main()
{
    // Initialization
    const int width = 1280;
    const int height = 800;

    InitWindow(width, height, "Pong");
    SetTargetFPS(60);

    Ball ball;
    ball.radius = 20;
    ball.x = (float) width / 2;
    ball.y = (float) height / 2;
    ball.speed_x = 7;
    ball.speed_y = 7;

    while (!WindowShouldClose()) {
        // Update
        if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_Q)) break;

        ball.update(width, height);

        // Draw
        BeginDrawing();
        ClearBackground(DARKBLUE);

        ball.draw();

        DrawRectangle(35, height/2 - 60, 25, 120, ORANGE);
        DrawRectangle(width - 60, height/2 - 60, 25, 120, ORANGE);
        DrawLine(width/2, 0, width/2, height, ORANGE);

        // DrawLine(0, height/2, width, height/2, ORANGE); // Dev ref (comment for prod)

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
