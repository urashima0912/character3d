#include "app.h"
#include "includes/raylib.h"
#include "scenes/level1.h"
#include "static_mesh.h"


game::App::App()
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

game::App::~App()
{
    delete currentScene;
    currentScene = nullptr;
    CloseWindow();
    #if defined(CHAR_GAME_DEBUG)
    TraceLog(LOG_INFO, "App destructor");
    #endif
}

void game::App::initialize()
{
    currentScene = new Level1(1);
}

void game::App::run(void)
{
    while(!WindowShouldClose())
    {
        currentScene->run();
    }
}