#pragma once

#include <SDL3/SDL.h>

#include <list>

#include "Point.hpp"
class AppState
{
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    //список из точек
    std::list<Point> points;


public:
    SDL_AppResult init()
    {
        if (!SDL_Init(SDL_INIT_VIDEO))
        {
            if (!SDL_CreateWindowAndRenderer(
                    "Упражнение 6"
                    , 480,360
                    , 0
                    // Адрес ук.
                    , &this->window
                    , &this->renderer
                    )
                )

            {
                SDL_Log("Could't create window/"
                        "renderer SDL: %s", SDL_GetError());
                return SDL_APP_FAILURE;
            }
            return SDL_APP_CONTINUE;
        }
    SDL_AppResult onEvent(SDL_Event &event);
    SDL_AppResult iterate();
};

