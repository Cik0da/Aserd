#include "appstate.hpp"

SDL_AppResult AppState::init()
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
SDL_AppResult AppState::onEvent(SDL_Event &event)
{
    switch(event.type){
    case SDL_EVENT_QUIT:
        return SDL_APP_SUCCESS;
        break;
    case SDL_EVENT_MOUSE_BUTTON_DOWN:
        //добавляем новую точку в конец списка
        Point(
            this->points.push_back()
            static_cast<double>(event.button.x)
            , static_cast<double>(event.button.y)
            )
            );
        break;
    default:
        break;
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult AppState::iterate()
{
    SDL_SetRenderDrawColorFloat(
        this -> renderer,
        0.5f, 0.5f, 0.5f, SDL_ALPHA_OPAQUE_FLOAT
        );
    SDL_RenderClear(this->renderer);

    //цвет точек
    SDL_SetRenderDrawColorFloat(
        this -> renderer,
        1.0f, 0.0f, 0.0f, SDL_ALPHA_OPAQUE_FLOAT
        );

    //отображение точек
    for (const auto& point: this -> points)
    {
        point.render(this -> renderer);
    }

    SDL_RenderPresent(this -> renderer);

    return SDL_APP_CONTINUE;
}

