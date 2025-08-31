
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_mouse.h>

#include <memory>
#include <iostream>

#include <stdio.h>

#define WIN_W 800.0
#define WIN_H 600.0

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

int old_main(int argc, char **argv)
{
    static std::unique_ptr<App> app = std::make_unique<App>();

    SDL_InitFlags init_flags = SDL_INIT_VIDEO;
    if (!SDL_Init(init_flags)) {
        SDL_Log("Could not init SDL: %s", SDL_GetError());
        return 1;
    }

    SDL_WindowFlags win_flags = 0;
    if (!SDL_CreateWindowAndRenderer("Tutorial", WIN_W, WIN_H, win_flags, &app->window, &app->renderer)) {
        SDL_Log("Could not create window and renderer: %s", SDL_GetError());
        return 1;
    }

    int winw, winh;
    if (!SDL_GetWindowSize(app->window, &winw, &winh)) { return 1; }
    printf("WINDOW width: %d, height: %d\n", winw, winh);

    float mx, my; // Mouse coords
    int press_count = 0;
    SDL_Event event;
    const bool *kbd_state = SDL_GetKeyboardState(nullptr);

    SDL_WarpMouseInWindow(app->window, (float) winw / 2, (float) winh / 2); // Centers the mouse on window at app start

    while (true) { // App loop

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
                break;

            case SDL_EVENT_MOUSE_MOTION:
                // Only runs when the mouse moves (does nothing when the mouse is still)
                SDL_Log("x, y: %f, %f", event.motion.x, event.motion.y);
                break;

            case SDL_EVENT_MOUSE_BUTTON_DOWN:
                SDL_Log("Clicks: %d", event.button.clicks);
                if (event.button.button == SDL_BUTTON_LEFT) {
                    SDL_Log("SDL_BUTTON_LEFT clicked");
                }
                if (event.button.button == SDL_BUTTON_RIGHT) {
                    SDL_Log("SDL_BUTTON_RIGHT clicked");
                }
                break;
            }

        } // Event loop

        // Update game state, draw the current frame

        // You can handle keys here too
        if (kbd_state[SDL_SCANCODE_H]) {
            SDL_Log("SDL_SCANCODE_H key was pressed");
        }

        // Always runs
        // SDL_MouseButtonFlags msbtn_flags = SDL_GetMouseState(&mx, &my);
        // SDL_Log("x, y: %f, %f", mx, my);

        // SDL_Delay(8); // ~120fps
        // SDL_Delay(10); // ~100fps
        // SDL_Delay(16); // ~60fps
        // SDL_Delay(34); // ~30fps
        SDL_Delay(67); // ~15fps
    } // App loop

end_app_loop:

    return 0;
}

