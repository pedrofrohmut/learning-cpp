#include <SDL3/SDL.h>
#include <cstdio>
#include <cstdlib>
#include <memory>

#define WIN_W 800.0
#define WIN_H 600.0
#define DELAY_60FPS 16

struct App
{
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    int winw = 0;
    int winh = 0;
    SDL_Event event;

    App(const char *title)
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

    bool HandleIO()
    {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_EVENT_QUIT:
                return false;
            case SDL_EVENT_KEY_DOWN:
                if ((event.key.mod == SDL_KMOD_LCTRL && event.key.key == SDLK_Q) ||
                    (event.key.mod == SDL_KMOD_RCTRL && event.key.key == SDLK_Q)) {
                    return false;
                }
                break;
            }
        }
        return true;
    }

    void Update() {}

    void Render() {}

    void run()
    {
        bool is_running = true;
        Uint64 start;
        Uint64 elapsed;
        Uint32 frames = 0;
        Uint64 ref_time = SDL_GetTicks();
        static char title_buffer[100];

        while (is_running) {
            start = SDL_GetTicks();

            is_running = HandleIO();

            if (is_running) {
                Update();

                Render();

                // Calculate fps
                ++frames;
                if (start - ref_time >= 1000) {
                    snprintf(title_buffer, sizeof(title_buffer), "SDL3 Tutorial (fps %d)", frames);
                    SDL_SetWindowTitle(window, title_buffer);
                    ref_time = start;
                    frames = 0;
                }

                // Calculate delay to keep fps stable
                elapsed = SDL_GetTicks() - start;
                if (elapsed < DELAY_60FPS) { // Avoid negative
                    SDL_Delay(DELAY_60FPS - elapsed);
                }
            }
        }

        SDL_Log("Quit event called. Quiting...");
    }

    ~App()
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
    const std::unique_ptr<App> app = std::make_unique<App>("SDL3 Tutorial");
    app->run();
    return 0;
}
