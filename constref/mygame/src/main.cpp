#include "SDL_keyboard.h"
#include "SDL_timer.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_messagebox.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

#include <SDL3_image/SDL_image.h>

#include <memory>
#include <cstdlib>
#include <string>

// Global Constants
const Uint64 ONE_SECOND_MS = 1000;
const Uint64 ONE_SECOND_NS = 1000 * 1000 * 1000;
const Uint64 DELAY_60FPS_MS = 16;
const Uint64 DELAY_60FPS_NS = 16666667;

std::string get_data_path_for(const std::string& path) // Pass by ref but const so the value wont change in the function
{
    return std::string(SDL_GetBasePath()) + "../data/" + path;
}

struct MyGame
{
    int winw = 1600; int winh = 900; // 16:9 HD+ 1600x900

    const char *win_title = "MyGame";
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Texture *idle_tex;

    int logical_width = 640;
    int logical_heigth = 320;

    // To hold SDL Data on window resizes
    int width;
    int height;

    MyGame() {}

    ~MyGame()
    {
        SDL_Log("INFO: Cleaning Up...");
        if (this->renderer) SDL_DestroyRenderer(this->renderer);
        if (this->window) SDL_DestroyWindow(this->window);
        SDL_Quit();
    }

    bool Init()
    {
        if (!SDL_Init(SDL_INIT_VIDEO)) {
            SDL_Log("ERROR: Could not init the SDL3 application: %s", SDL_GetError());
            return false;
        }

        this->window = SDL_CreateWindow(this->win_title, this->winw, this->winh, SDL_WINDOW_RESIZABLE);
        if (this->window == nullptr) {
            SDL_Log("ERROR: Could not create a window: %s", SDL_GetError());
            return false;
        }

        this->renderer = SDL_CreateRenderer(this->window, nullptr);
        if (this->renderer == nullptr) {
            SDL_Log("ERROR: Could not create the renderer: %s", SDL_GetError());
            return false;
        }

        // Sizes the size of the presentation idependently of the size of the window
        if (!SDL_SetRenderLogicalPresentation(this->renderer, this->logical_width, this->logical_heigth,
                SDL_LOGICAL_PRESENTATION_LETTERBOX)) {
            SDL_Log("ERROR: Could not set the logical presentation: %s", SDL_GetError());
            return false;
        }

        return true;
    }

    bool HandleIO()
    {
        SDL_Event event = {};
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_EVENT_QUIT:
                return false;
            case SDL_EVENT_WINDOW_RESIZED:
                this->width = event.window.data1;
                this->height = event.window.data2;
                break;
            }
        }
        return true;
    }

    void Update() {}

    void Render() {}

    void Run()
    {
        // Loag game assets
        idle_tex = IMG_LoadTexture(this->renderer, get_data_path_for("idle.png").c_str());
        SDL_SetTextureScaleMode(this->idle_tex, SDL_SCALEMODE_NEAREST);

        const bool *keys = SDL_GetKeyboardState(nullptr);
        float playerX = 150.0;
        const float floor_h = this->logical_heigth;
        bool flip_horizontal = false;

        SDL_Log("INFO: SDL Application initiated and running");
        bool running = true;

        Uint64 frame_time_acc_ns = 0;
        Uint32 fps = 0;

        Uint64 prev_time_ms = SDL_GetTicks();

        while (true) // Main game loop
        {
            Uint64 start_ns = SDL_GetTicksNS();

            Uint64 now_time_ms = SDL_GetTicks(); // To calculate the player movement based on time

            float delta_time_sec = (now_time_ms - prev_time_ms) / 1000.0f;

            running = HandleIO();

            if (!running) break;

        // Update begin
            const float move_delta = 100.0f;
            float move_amount = 0;
            if (keys[SDL_SCANCODE_A]) {
                move_amount -= move_delta;
                flip_horizontal = true;
            }
            if (keys[SDL_SCANCODE_D]) {
                move_amount += move_delta;
                flip_horizontal = false;
            }
            // Devide by delta time makes the movement base on time not on random values
            // Without delta time it would only work on fixed and low fps
            playerX += move_amount * delta_time_sec;
        // Update end

        // Render begin
            // Make the buffer renderer
            SDL_SetRenderDrawColor(this->renderer, 26, 27, 44, 255); // Toukyou Night #1a1b2c
            SDL_RenderClear(this->renderer);

            const float sprite_size = 32;
            SDL_FRect src_rect  = {
                .x = 0,
                .y = 0,
                .w = sprite_size,
                .h = sprite_size
            };
            SDL_FRect dest_rect = {
                .x = playerX,
                .y = floor_h - sprite_size,
                .w = sprite_size,
                .h = sprite_size
            };
            // SDL_RenderTexture(this->renderer, this->idle_tex, &src_rect, &dest_rect);
            SDL_RenderTextureRotated(this->renderer, this->idle_tex, &src_rect, &dest_rect, 0, nullptr,
                    (flip_horizontal) ? SDL_FLIP_HORIZONTAL :  SDL_FLIP_NONE);

            // Draws the processed buffer in the window
            SDL_RenderPresent(this->renderer);
        // Render end

        // FPS / Frame Time begin
            Uint64 frame_time_ns = SDL_GetTicksNS() - start_ns;

            // Calculate the delay to limit it and keep a regular fps
            if (frame_time_ns < DELAY_60FPS_NS) {
                Uint64 delay_ns = DELAY_60FPS_NS - frame_time_ns;
                SDL_DelayNS(delay_ns);
            }

            // Calculate fps based on frame time in ns
            ++fps;
            frame_time_acc_ns += DELAY_60FPS_NS;
            if (frame_time_acc_ns >= ONE_SECOND_NS) {
                SDL_Log("FPS: %d, Frame time: %zu nano seconds", fps, frame_time_ns);
                // SDL_Log("Width: %d, Height: %d", this->width, this->height);
                fps = 0;
                frame_time_acc_ns = 0;
            }
        // FPS / Frame Time end

            prev_time_ms = now_time_ms;
        }

        // Clean up assets
        SDL_DestroyTexture(this->idle_tex);

        SDL_Log("INFO: Quit event called. Quiting...");
    }
};

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    const std::unique_ptr<MyGame> app = std::make_unique<MyGame>();
    if (!app->Init()) return 1;
    app->Run();
    return 0;
}
