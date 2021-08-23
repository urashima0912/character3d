#include "scene.h"
#include "../config.h"
#include "static_mesh.h"
#include "player.h"

game::Scene::Scene(int id)
{
    // Player Initilize.
    this->gameObjects.push_back(new Player());

    // Ground Initilize.
    Transform transform = {0};
    transform.position = (Vector3){0};
    transform.rotation = (Vector3){0};
    transform.size = (Vector3){10.0f, 0.5f, 10.0f};
    this->gameObjects.push_back(new StaticMesh(transform, GREEN));

    #if defined(CHAR_GAME_DEBUG)
    TraceLog(LOG_INFO, "Scene constructor");
    #endif
}

game::Scene::~Scene(void)
{
    for (std::size_t i=0; i < gameObjects.size(); i++)
    {
        delete gameObjects[i];
        gameObjects[i] = nullptr;
    }

    #if defined(CHAR_GAME_DEBUG)
    TraceLog(LOG_INFO, "Scene destructor");
    #endif
}

void game::Scene::run(void)
{
    this->update();
    this->draw();
}

void game::Scene::update(void)
{
    std::vector<GameObject *>::iterator it = gameObjects.begin();
    for (it; it != gameObjects.end(); it++)
        (*it)->update();
}

void game::Scene::draw(void)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

    Player *player = dynamic_cast<Player*>(gameObjects[0]);
    BeginMode3D(player->getCamera());
    
    std::vector<GameObject *>::iterator it = gameObjects.begin();
    for(it; it != gameObjects.end(); it++)
        (*it)->draw();

    DrawGrid(20, 1.0f);
    EndMode3D();

    EndDrawing();
}
