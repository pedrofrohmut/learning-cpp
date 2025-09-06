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

std::string get_data_path_for(const char *path)
{
    return std::string(SDL_GetBasePath()) + "../data/" + path;
}

struct MyGame
{
    int winw = 800;
    int winh = 600;
    const char *win_title = "MyGame";
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Texture *idle_tex;

    MyGame()
    {
        if (!SDL_Init(SDL_INIT_VIDEO)) {
            SDL_Log("ERROR: Could not init the SDL3 application: %s", SDL_GetError());
            exit(1);
        }

        this->window = SDL_CreateWindow(this->win_title, this->winw, this->winh, 0);
        if (this->window == nullptr) {
            SDL_Log("ERROR: Could not create a window: %s", SDL_GetError());
            exit(1);
        }

        this->renderer = SDL_CreateRenderer(this->window, nullptr);
        if (this->renderer == nullptr) {
            SDL_Log("ERROR: Could not create the renderer: %s", SDL_GetError());
            exit(1);
        }

        idle_tex = IMG_LoadTexture(this->renderer, get_data_path_for("idle.png").c_str());
        SDL_SetTextureScaleMode(this->idle_tex, SDL_SCALEMODE_NEAREST);
    }

    ~MyGame()
    {
        SDL_Log("INFO: Cleaning Up...");
        if (this->renderer) SDL_DestroyRenderer(this->renderer);
        if (this->window) SDL_DestroyWindow(this->window);
        SDL_Quit();
    }

    bool HandleIO()
    {
        SDL_Event event = {};
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_EVENT_QUIT:
                return false;
            }
        }
        return true;
    }

    void Update() {}

    void Render()
    {
        // Make the buffer renderer
        SDL_SetRenderDrawColor(this->renderer, 26, 27, 44, 255); // Toukyou Night #1a1b2c
        SDL_RenderClear(this->renderer);

        SDL_FRect src_rect = { .x = 0, .y = 0, .w = 32, .h = 32 };
        SDL_RenderTexture(this->renderer, this->idle_tex, &src_rect, nullptr);

        // Draws the processed buffer in the window
        SDL_RenderPresent(this->renderer);
    }

    void Run()
    {
        SDL_Log("INFO: SDL Application initiated and running");
        bool running = true;

        Uint64 frame_time_acc_ns = 0;
        Uint32 fps = 0;

        while (true) // Main game loop
        {
            Uint64 start_ns = SDL_GetTicksNS();

            running = HandleIO();

            if (!running) break;

            Update();

            Render();

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
                fps = 0;
                frame_time_acc_ns = 0;
            }
        }

        // Clean up assets
        SDL_DestroyTexture(this->idle_tex);

        SDL_Log("INFO: Quit event called. Quiting...");
    }
};

int main(int argc, char **argv)
{
    const std::unique_ptr<MyGame> app = std::make_unique<MyGame>();
    app->Run();
    return 0;
}
