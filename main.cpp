#define SDL_MAIN_USE_CALLBACKS 1

#include<SDL3/SDL_main.h>

#include "Appstate.hpp"

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    if(auto app = new AppState)
    {
        *appstate = static_cast<void*>(app);
        return app -> init();
    }

    return SDL_APP_FAILURE;
}

SDL_AppResult SDL_AppEvent(void *appstate , SDL_Event *event)
{
    if(auto app = static_cast<AppState*>(appstate))
    {
        return app->onEvent(*event);
    }

    return SDL_APP_FAILURE;
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
    if(auto app = static_cast<AppState*>(appstate))
    {
        return app->iterate();
    }

    return SDL_APP_FAILURE;
}

void SDL_AppQuit(void *appstate , SDL_AppResult result)
{
    if(auto app = static_cast<AppState*>(appstate))
    {
        delete app;
    }
}
