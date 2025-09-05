// #define SDL_MAIN_USE_CALLBACKS 1

#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_messagebox.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <memory>
#include <string>

struct App
{
    int winw = 800;
    int winh = 600;
    std::string win_title = "MyGame";
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    App()
    {
        if (!SDL_Init(SDL_INIT_VIDEO)) {
            SDL_Log("ERROR: Could not init the SDL3 application: %s", SDL_GetError());
            exit(1);
        }

        this->window = SDL_CreateWindow(this->win_title.c_str(), this->winw, this->winh, 0);
        if (this->window == nullptr) {
            SDL_Log("ERROR: Could not create a window: %s", SDL_GetError());
            exit(1);
        }

        this->renderer = SDL_CreateRenderer(this->window, nullptr);
        if (this->renderer == nullptr) {
            SDL_Log("ERROR: Could not create the renderer: %s", SDL_GetError());
            exit(1);
        }
    }

    ~App()
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

        while (true) // Main game loop
        {
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

            // Draws the processed buffer in the window
            SDL_RenderPresent(this->renderer);

            SDL_Delay(16);
        }

        SDL_Log("INFO: Quit event called. Quiting...");
    }
};

int main(int argc, char **argv)
{
    const std::unique_ptr<App> app = std::make_unique<App>();
    app->Run();
    return 0;
}
