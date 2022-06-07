#include "SDL.h"
#include "stdio.h"
#include "iostream"
#include "math.h"
#include "cmath"


#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

float map(float minX, float maxX, float minPxX, float maxPxX, float x)
{
    return (x - minX) / (maxX - minX) * (maxPxX - minPxX) + minPxX;
}

int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    const auto Width = 1280;
    const auto Heigth = 720;
    SDL_Window *w = SDL_CreateWindow("Graphs", 63, 126, Width, Heigth, SDL_WINDOW_BORDERLESS);
    SDL_Renderer *r = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED);
    for (auto done = false; !done;)
    {
        SDL_Event e;
        while (SDL_WaitEvent(&e))
        {
            switch (e.type)
            {
            case SDL_QUIT:
                done = true;
                break;
            }
            SDL_SetRenderDrawColor(r, 0xff, 0xff, 0xff, 0xff);
            SDL_RenderClear(r);
            SDL_SetRenderDrawColor(r, 0xee, 0xee, 0xee, 0xff);

            // Линии, которые делят окно на квадратики)
            {
            for (float x = -10; x < 10; ++x) {
                SDL_RenderDrawLine(r,
                                   map(-10, 10, 0, Width, x), map(-5, 5, Heigth, 0, -5),
                                   map(-10, 10, 0, Width, x), map(-5, 5, Heigth, 0, +5));
            }
            for (float y = -5; y < 5; ++y) {
                SDL_RenderDrawLine(r,
                                   map(-10, 10, 0, Width, -10), map(-5, 5, Heigth, 0, y),
                                   map(-10, 10, 0, Width, 10), map(-5, 5, Heigth, 0, y));
            }
            }

            // Ось абцисс и ординат + функция
            {
                SDL_SetRenderDrawColor(r, 0xee, 0xc0, 0xc0, 0xff);
                SDL_RenderDrawLine(r,
                                map(-10, 10, 0, Width, -10), map(-5, 5, Heigth, 0, 0),
                                map(-10, 10, 0, Width, 10), map(-5, 5, Heigth, 0, 0));
                SDL_RenderDrawLine(r,
                                map(-10, 10, 0, Width, 0), map(-5, 5, Heigth, 0, -5),
                                map(-10, 10, 0, Width, 0), map(-5, 5, Heigth, 0, +5));
                SDL_SetRenderDrawColor(r, 0x00, 0x00, 0x00, 0xff);
            }
            
            auto oldX = -1;
            auto oldY = 0;
            for (float x = -5; x <= 3; x += 0.01) // x от -5 до 3 по условию задачи
            {
                auto y = exp(-2) / (x - 5); // ТУТ МОЖНО ИЗМЕНЯТЬ ФУНКЦИЮ
                auto newX = map(-10, 10, 0, Width, x);
                auto newY = map(-5, 5, Heigth, 0, y);
                if (oldX >= 0)
                    SDL_RenderDrawLine(r, oldX, oldY, newX, newY);
                oldX = newX;
                oldY = newY;
            }
            SDL_RenderPresent(r);
        }
        SDL_Quit();
    }
    return 0;
}
