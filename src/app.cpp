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
    for (int i=0; i < 2; i++)
    {
        delete objects[i];
        objects[i] = nullptr;
    }

    
    CloseWindow();
    #if defined(CHAR_GAME_DEBUG)
    TraceLog(LOG_INFO, "App destructor");
    #endif
}

void App::initialize()
{
    // Player Initilize.
    objects.push_back(new Player());

    // Ground Initilize.
    Transform transform = {0};
    transform.position = (Vector3){0};
    transform.rotation = (Vector3){0};
    transform.size = (Vector3){10.0f, 0.5f, 10.0f};
    objects.push_back(new StaticMesh(transform, GREEN));
}

void App::run(void)
{
    while(!WindowShouldClose())
    {
        this->update();
        this->draw();
    }
}

void App::update(void)
{
    std::vector<GameObject *>::iterator it = objects.begin();
    for (it; it != objects.end(); it++)
        (*it)->update();
}

void App::draw(void)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

    Player *player = dynamic_cast<Player*>(objects[0]);
    BeginMode3D(player->getCamera());
    
    std::vector<GameObject *>::iterator it = objects.begin();
    for(it; it != objects.end(); it++)
        (*it)->draw();

    DrawGrid(20, 1.0f);
    EndMode3D();

    EndDrawing();
}