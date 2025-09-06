#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_messagebox.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

#include <SDL3_image/SDL_image.h>

#include <memory>
#include <cstdlib>

const Uint32 ONE_SECOND = 1000;

struct MyGame
{
    int winw = 800;
    int winh = 600;
    const char *win_title = "MyGame";
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Texture *idleTex;

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

        idleTex = IMG_LoadTexture(this->renderer, "../data/idle.png");
    }

    ~MyGame()
    {
        SDL_Log("INFO: Cleaning Up...");
        if (this->renderer) SDL_DestroyRenderer(this->renderer);
        if (this->window) SDL_DestroyWindow(this->window);
        SDL_Quit();
    }

    void Run()
    {
        SDL_Log("INFO: SDL Application initiated and running");
        bool running = true;

        Uint32 frame_time_acc_ms = 0;
        Uint32 fps = 0;

        while (true) // Main game loop
        {
            Uint64 start = SDL_GetTicks();

            SDL_Event event = {};
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                case SDL_EVENT_QUIT:
                    running = false;
                    break;
                }
            }

            if (!running) break;

            // Make the buffer renderer
            SDL_SetRenderDrawColor(this->renderer, 26, 27, 44, 255); // Toukyou Night #1a1b2c
            SDL_RenderClear(this->renderer);

            SDL_RenderTexture(this->renderer, this->idleTex, nullptr, nullptr);

            // Draws the processed buffer in the window
            SDL_RenderPresent(this->renderer);

            SDL_Delay(16);

            // Track FPS and Frame Time
            Uint64 frame_time_ms = SDL_GetTicks() - start;
            ++fps;
            frame_time_acc_ms += frame_time_ms;
            if (frame_time_acc_ms >= ONE_SECOND) {
                SDL_Log("FPS: %d, Frame time: %zums", fps, frame_time_ms);
                fps = 0;
                frame_time_acc_ms = 0;
            }
        }

        // Clean up assets
        SDL_DestroyTexture(this->idleTex);

        SDL_Log("INFO: Quit event called. Quiting...");
    }
};

int main(int argc, char **argv)
{
    const std::unique_ptr<MyGame> app = std::make_unique<MyGame>();
    app->Run();
    return 0;
}
