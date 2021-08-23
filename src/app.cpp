#include "app.h"
#include "includes/raylib.h"

#include "static_mesh.h"

using namespace game;

App::App()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SCREEN_TITLE
    );

    SetTargetFPS(SCREEN_FPS);
    #if defined(CHAR_GAME_DEBUG)
    TraceLog(LOG_INFO, "App constructor");
    #endif

    this->initialize();
}

App::~App()
{
    delete currentScene;
    currentScene = nullptr;
    CloseWindow();
    #if defined(CHAR_GAME_DEBUG)
    TraceLog(LOG_INFO, "App destructor");
    #endif
}

void App::initialize()
{
    currentScene = new Scene(1);
}

void App::run(void)
{
    while(!WindowShouldClose())
    {
        currentScene->run();
    }
}