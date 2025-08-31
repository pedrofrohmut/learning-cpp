#include <SDL3/SDL.h>
#include <cstdio>
#include <cstdlib>
#include <memory>

#define WIN_W 800.0
#define WIN_H 600.0
#define DELAY_60FPS 16

struct SDLApplication
{
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    int winw = 0;
    int winh = 0;
    SDL_Event event;

    SDLApplication(const char *title)
    {
        SDL_InitFlags init_flags = SDL_INIT_VIDEO;
        if (!SDL_Init(init_flags)) {
            SDL_Log("Could not init SDL: %s", SDL_GetError());
            exit(1);
        }

        SDL_WindowFlags win_flags = 0;
        if (!SDL_CreateWindowAndRenderer(title, WIN_W, WIN_H, win_flags, &window, &renderer)) {
            SDL_Log("Could not create window and renderer: %s", SDL_GetError());
            exit(1);
        }

        if (!SDL_GetWindowSize(window, &winw, &winh)) {
            SDL_Log("Could not get window size: %s", SDL_GetError());
            exit(1);
        }

        SDL_Log("Window created with width of %d and height of %d", winw, winh);
    }

    void run()
    {
        while (true) { // Main loop

            while (SDL_PollEvent(&event)) { // Event loop
                switch (event.type) {
                case SDL_EVENT_QUIT:
                    goto end_app_loop;
                case SDL_EVENT_KEY_DOWN:
                    if ((event.key.mod == SDL_KMOD_LCTRL && event.key.key == SDLK_Q) ||
                        (event.key.mod == SDL_KMOD_RCTRL && event.key.key == SDLK_Q)) {
                        goto end_app_loop;
                    }
                    break;
                }
            } // Event loop

            SDL_Delay(DELAY_60FPS);
        } // Main loop

    end_app_loop:
        SDL_Log("Quit event called. Quiting...");
        return;
    }

    ~SDLApplication()
    {
        SDL_Log("Closing app...");
        // Clean up
        if (renderer) SDL_DestroyRenderer(renderer);
        if (window) SDL_DestroyWindow(window);
        SDL_Quit();
        SDL_Log("Render and Window cleaned up. SDL App Quit");
    }
};

int main(int argc, const char **argv)
{
    const std::unique_ptr<SDLApplication> app = std::make_unique<SDLApplication>("SDL3 Tutorial");
    app->run();
    return 0;
}
