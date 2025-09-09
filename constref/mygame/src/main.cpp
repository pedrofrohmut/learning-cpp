#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include <memory>
#include <string>
#include <vector>

#include "SDL_keyboard.h"
#include "animation.h"

// Global Constants
// const Uint64 ONE_SECOND_MS = 1000;
// const Uint64 ONE_SECOND_NS = 1000 * 1000 * 1000;
// const Uint64 DELAY_60FPS_MS = 16;
// const Uint64 DELAY_60FPS_NS = 16666667;

std::string get_data_path_for(const std::string &file_path)
{
    return std::string(SDL_GetBasePath()) + "../data/" + file_path;
}

struct SDLState
{
    int window_width = 1600;
    int window_height = 900;
    int logical_width = 640;
    int logical_height = 320;
    int width;
    int height;
    SDL_Window *window;
    SDL_Renderer *renderer;
};

bool init_state(SDLState *state)
{
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("ERROR: Could not init the SDL3 application: %s", SDL_GetError());
        return false;
    }

    state->window = SDL_CreateWindow("My Game", state->window_width, state->window_height, SDL_WINDOW_RESIZABLE);
    if (state->window == nullptr) {
        SDL_Log("ERROR: Could not create a window: %s", SDL_GetError());
    }

    state->renderer = SDL_CreateRenderer(state->window, nullptr);
    if (state->renderer == nullptr) {
        SDL_Log("ERROR: Could not create a renderer: %s", SDL_GetError());
        return false;
    }

    // Sizes the presentation independently of the size of the window
    if (!SDL_SetRenderLogicalPresentation(state->renderer, state->logical_width, state->logical_height,
                                          SDL_LOGICAL_PRESENTATION_LETTERBOX)) {
        SDL_Log("ERROR: Could not set the logical presentation: %s", SDL_GetError());
        return false;
    }

    return true;
}

void cleanup(SDLState *state)
{
    SDL_Log("INFO: Cleaning Up ...");
    if (state->renderer) SDL_DestroyRenderer(state->renderer);
    if (state->window) SDL_DestroyWindow(state->window);
    SDL_Quit();
}

struct Resources
{
    const int ANIMATION_PLAYER_IDLE = 0; // Represents the index animation in the player animations vector
    std::vector<Animation> playerAnimations;
    std::vector<SDL_Texture *> textures;
    SDL_Texture *texture_idle;

    SDL_Texture *load_texture(SDL_Renderer *renderer, const std::string &file_path)
    {
        SDL_Texture *texture = IMG_LoadTexture(renderer, file_path.c_str());
        SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
        this->textures.push_back(texture);
        return texture;
    }

    void load(SDLState *state)
    {
        this->playerAnimations.resize(5);
        this->playerAnimations[ANIMATION_PLAYER_IDLE] = Animation(8, 1.6f);
        this->texture_idle = this->load_texture(state->renderer, get_data_path_for("idle.png"));
    }

    void unload()
    {
        for (SDL_Texture *texture : this->textures) {
            SDL_DestroyTexture(texture);
        }
    }
};

bool handle_events(SDLState *state)
{
    SDL_Event event = {};
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_EVENT_QUIT:
            return false;
        case SDL_EVENT_WINDOW_RESIZED:
            state->width = event.window.data1;
            state->height = event.window.data2;
            break;
        }
    }
    return true;
}

struct GameState
{
    const bool *keys;
    float player_x;
    bool flip_horizontal;

    GameState(): keys(SDL_GetKeyboardState(nullptr)), player_x(150.0), flip_horizontal(false) {}
};

void update(GameState *game_state, Uint64 now_time_ms, Uint64 prev_time_ms)
{
        const float move_delta = 100.0f;
        float move_amount = 0;

        if (game_state->keys[SDL_SCANCODE_A]) {
            move_amount -= move_delta;
            game_state->flip_horizontal = true;
        }

        if (game_state->keys[SDL_SCANCODE_D]) {
            move_amount += move_delta;
            game_state->flip_horizontal = false;
        }

        // Devide by delta time makes the movement base on time not on random values
        // Without delta time it would only work on fixed and low fps
        const float delta_time_sec = (now_time_ms - prev_time_ms) / 1000.0f; // Divide by 1000 to convert to sec
        game_state->player_x += move_amount * delta_time_sec;
}

int main()
{
    const std::unique_ptr<SDLState> state = std::make_unique<SDLState>();
    if (!init_state(state.get())) {
        SDL_Log("ERROR: Could not init SDLState");
        return 1;
    }

    const std::unique_ptr<GameState> game_state = std::make_unique<GameState>();

    // Load game assets
    Resources resources;
    resources.load(state.get());

    // The y coordinate of the game floor
    const float floor_h = state->logical_height;

    // Reference to calculate delta_time to use on game controls
    Uint64 prev_time_ms = SDL_GetTicks();

    // Main loop
    while (true) {
        const Uint64 now_time_ms = SDL_GetTicks();

        // Handle events
        const bool is_running = handle_events(state.get());
        if (!is_running) break;

        // Update
        update(game_state.get(), now_time_ms, prev_time_ms);

        SDL_SetRenderDrawColor(state->renderer, 26, 27, 44, 255); // Toukyou Night #1a1b2c
        SDL_RenderClear(state->renderer);

        const float sprite_size = 32;
        SDL_FRect src_rect = {
            .x = 0,
            .y = 0,
            .w = sprite_size,
            .h = sprite_size,
        };
        SDL_FRect dest_rect = {
            .x = game_state->player_x,
            .y = floor_h - sprite_size,
            .w = sprite_size,
            .h = sprite_size,
        };
        SDL_RenderTextureRotated(state->renderer, resources.texture_idle, &src_rect, &dest_rect, 0, nullptr,
                                 (game_state->flip_horizontal) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);

        SDL_RenderPresent(state->renderer); // Draws the processed buffer in the window

        SDL_Delay(16); // TODO: Calc the delay

        prev_time_ms = now_time_ms;
    }

    resources.unload();
    cleanup(state.get());

    return 0;
}
