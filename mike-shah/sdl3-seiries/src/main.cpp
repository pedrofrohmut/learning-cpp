#include <SDL3/SDL.h>

#include <memory>
#include <iostream>

struct App
{
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    ~App()
    {
        SDL_Log("Closing app...");
        // Clean up
        if (renderer) SDL_DestroyRenderer(renderer);
        if (window) SDL_DestroyWindow(window);
        SDL_Quit();
        std::cout << "Render and Window cleaned up. SDL App Quit\n";
    }
};

int main(int argc, char **argv)
{
    static std::unique_ptr<App> app = std::make_unique<App>();

    SDL_InitFlags init_flags = SDL_INIT_VIDEO;
    if (!SDL_Init(init_flags)) {
        SDL_Log("Could not init SDL: %s", SDL_GetError());
        return 1;
    }

    SDL_WindowFlags win_flags = 0;
    if (!SDL_CreateWindowAndRenderer("Tutorial", 800, 600, win_flags, &app->window, &app->renderer)) {
        SDL_Log("Could not create window and renderer: %s", SDL_GetError());
        return 1;
    }


    int press_count = 0;
    while (true) { // App loop
        SDL_Event event;

        while (SDL_PollEvent(&event)) { // Event handling loop. poll until all events are handled
            //Decides what to do in the current event

            switch (event.type) {
            case SDL_EVENT_QUIT:
                goto end_app_loop;
            case SDL_EVENT_KEY_DOWN:
                SDL_Log("[%d] Key pressed: %d", press_count, event.key.key);
                press_count += 1;
                if (event.key.key == SDLK_ESCAPE) {
                    goto end_app_loop;
                }
            }

        } // Event loop

        // Update game state, draw the current frame

        SDL_Delay(16); // ~60fps
    } // App loop
end_app_loop:

    return 0;
}
