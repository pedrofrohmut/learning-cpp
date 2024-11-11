#include <raylib.h>
#include <iostream>

// Video: https://www.youtube.com/watch?v=VLJlTaFvHo4

#define PADDLE_WIDTH 25
#define PADDLE_HEIGHT 120
#define WINDOW_PADDING 35


class Paddle
{
public:
    float x, y;
    int height, width;
    float speed_x, speed_y;
    float radius;

    void draw()
    {
        DrawRectangle(x, y, width, height, ORANGE);
    }

    void update()
    {
        y += speed_y;
    }

    Rectangle getPaddleRec()
    {
        Rectangle rec = { .x = x, .y = y, .width = (float) width, .height = (float) height };
        return rec;
    }

};

class Ball
{
public:
    float x, y;
    float speed_x, speed_y;
    float radius;
    Color color;

    void draw()
    {
        DrawCircle(x, y, radius, color);
    }

    void update(int win_width, int win_height, Rectangle prec, Rectangle crec)
    {
        bool p_collision =
            CheckCollisionCircleRec((Vector2) { .x = x , .y = y }, radius, prec);
        bool c_collision =
            CheckCollisionCircleRec((Vector2) { .x = x , .y = y }, radius, crec);

        if (p_collision || c_collision) speed_x *= -1;

        // Wall collision
        if (x + radius >= win_width || x - radius <= 0) speed_x *= -1;
        if (y + radius >= win_height || y - radius <= 0) speed_y *= -1;

        // Move
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
    ball.is_colliding = false;
    ball.color = ORANGE;

    // Player pladdle
    Paddle ppd;
    ppd.x = WINDOW_PADDING;
    ppd.y = height/2 - PADDLE_HEIGHT / 2;
    ppd.width = PADDLE_WIDTH;
    ppd.height = PADDLE_HEIGHT;

    // CPU paddle
    Paddle cpd;
    cpd.x = width - (WINDOW_PADDING + PADDLE_WIDTH);
    cpd.y = height/2 - PADDLE_HEIGHT / 2;
    cpd.width = PADDLE_WIDTH;
    cpd.height = PADDLE_HEIGHT;


    while (!WindowShouldClose()) {
        // Update
        if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_Q)) break;

        // Player paddle go up
        if (IsKeyDown(KEY_UP)) ppd.speed_y = -7;
        if (IsKeyReleased(KEY_UP)) ppd.speed_y = 0;

        // Player paddle go down
        if (IsKeyDown(KEY_DOWN)) { ppd.speed_y = 7; }
        if (IsKeyReleased(KEY_DOWN)) { ppd.speed_y = 0; }

        // Cpu paddle go up
        if (IsKeyDown(KEY_W)) cpd.speed_y = -7;
        if (IsKeyReleased(KEY_W)) cpd.speed_y = 0;

        // Cpu paddle go down
        if (IsKeyDown(KEY_S)) cpd.speed_y = 7;
        if (IsKeyReleased(KEY_S)) cpd.speed_y = 0;

        // Update for Ball
        Rectangle ppd_rec = ppd.getPaddleRec();
        Rectangle cpd_rec = cpd.getPaddleRec();
        ball.update(width, height, ppd_rec, cpd_rec);

        // Update for Player
        ppd.update();

        // Update Cpu
        cpd.update();

        BeginDrawing();
            ClearBackground(DARKBLUE);
            ball.draw();
            ppd.draw();
            cpd.draw();
            DrawLine(width/2, 0, width/2, height, ORANGE);
            //DrawLine(0, height/2, width, height/2, ORANGE); // Dev ref (comment for prod)
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
