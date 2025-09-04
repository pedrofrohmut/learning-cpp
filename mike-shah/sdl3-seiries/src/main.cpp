#include <SDL3/SDL.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_render.h>
#include <cstdlib>
#include <memory>
#include <string>

#define WIN_W 800.0
#define WIN_H 600.0
#define DELAY_60FPS 16

struct App
{
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Event event;
    SDL_Surface *surface = nullptr;
    SDL_Texture *texture = nullptr;
    int texw, texh;
    int winw, winh;
    std::string title = "SDL3 Tutorial";

    App()
    {

        SDL_InitFlags init_flags = SDL_INIT_VIDEO;
        if (!SDL_Init(init_flags)) {
            SDL_Log("Could not init SDL: %s", SDL_GetError());
            exit(1);
        }

        SDL_WindowFlags win_flags = 0;
        if (!SDL_CreateWindowAndRenderer(this->title.c_str(), WIN_W, WIN_H, win_flags, &this->window, &this->renderer)) {
            SDL_Log("Could not create window and renderer: %s", SDL_GetError());
            exit(1);
        }

        if (!SDL_GetWindowSize(this->window, &this->winw, &this->winh)) {
            SDL_Log("Could not get window size: %s", SDL_GetError());
            exit(1);
        }

        SDL_Log("Window created with width of %d and height of %d", this->winw, this->winh);

        // Load bmp from base path
        char *bmp_path;
        SDL_asprintf(&bmp_path, "%sbackground.bmp", SDL_GetBasePath()); // SDL_Log("BMP Path: '%s'", bmp_path);
        this->surface = SDL_LoadBMP(bmp_path);
        if (this->surface == nullptr) {
            SDL_Log("Could not load the bmp image: %s", SDL_GetError());
            exit(1);
        }
        SDL_Log("BMP Loaded");

        // Clean up string for path
        SDL_free(bmp_path);

        // Use surface to make the texture
        this->texw = this->surface->w;
        this->texh = this->surface->h;
        this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
        if (this->texture == nullptr) {
            SDL_Log("Could not create texture: %s", SDL_GetError());
            exit(1);
        }
        SDL_Log("Texture loaded");

        // Clean up surface not needed anymore
        SDL_DestroySurface(this->surface);
    }

    ~App()
    {
        SDL_Log("Closing app...");
        // Clean up
        if (this->renderer) SDL_DestroyRenderer(this->renderer);
        if (this->window) SDL_DestroyWindow(this->window);
        SDL_Quit();
        SDL_Log("Render and Window cleaned up. SDL App Quit");
    }

    bool HandleIO()
    {
        while (SDL_PollEvent(&this->event)) {
            switch (this->event.type) {
            case SDL_EVENT_QUIT:
                return false;
            case SDL_EVENT_KEY_DOWN:
                if ((this->event.key.mod == SDL_KMOD_LCTRL && this->event.key.key == SDLK_Q) ||
                    (this->event.key.mod == SDL_KMOD_RCTRL && this->event.key.key == SDLK_Q)) {
                    return false;
                }
                break;
            }
        }
        return true;
    }

    void Update() {}

    void Render() {
        // Set the background texture
        SDL_RenderTexture(this->renderer, this->texture, nullptr, nullptr);

        // End Drawing
        SDL_RenderPresent(this->renderer); // Put the new renderer on screen
    }

    void run()
    {
        bool is_running = true;

        // Values to calculate FPS and delay for target fps
        Uint64 ref_time = SDL_GetTicks();
        const Uint32 num_of_sec = 5;
        const Uint32 sec_in_ms = num_of_sec * 1000;
        Uint32 frames = 0;
        Uint32 current_fps = 0;
        Uint64 frame_time = 0;

        while (is_running) {
            Uint64 start = SDL_GetTicks();
            Uint64 start_frame_time = SDL_GetTicks(); // Keep it separate from 'start' so is easy to change to NS if needed

            is_running = HandleIO();

            if (!is_running) { break; }

            Update();

            Render();

            // Calculate fps
            ++frames;
            if ((start - ref_time) >= sec_in_ms) {
                Uint32 fps = frames / num_of_sec;

                this->title = "SDL3 Tutorial (fps: " + std::to_string(fps) + ", ft: " + std::to_string(frame_time) + ")";
                SDL_Log("%s", this->title.c_str());

                if (current_fps != fps) { // Minimal updates on window title
                    SDL_SetWindowTitle(this->window, this->title.c_str());
                }

                current_fps = fps;
                ref_time = start;
                frames = 0;
            }

            // Calculate delay to keep fps stable
            Uint64 elapsed = SDL_GetTicks() - start;
            if (elapsed < DELAY_60FPS) { // Avoid negative
                SDL_Delay(DELAY_60FPS - elapsed);
            }

            // Track frame time (ms)
            frame_time = SDL_GetTicks() - start_frame_time;
        }

        SDL_Log("Quit event called. Quiting...");
    }
};

int main(int argc, const char **argv)
{
    const std::unique_ptr<App> app = std::make_unique<App>();
    app->run();
    return 0;
}
