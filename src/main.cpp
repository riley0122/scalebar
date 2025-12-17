#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

int main() {    
    SDL_Window *window;
    
    SDL_Init(SDL_INIT_VIDEO);
    
    window = SDL_CreateWindow("Test", 720, 480, 0);

    bool done = false;
    while (!done) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                done = true;
            }
        }
    }

    return 0;
}