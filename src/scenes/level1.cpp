#include "level1.h"
#include "../player.h"
#include "../static_mesh.h"


game::Level1::Level1(int32_t id)
{
    this->id = id;

    this->gameObjects.push_back(new Player());

    // Ground Initilize.
    Transform transform = {0};
    transform.position = (Vector3){0};
    transform.rotation = (Vector3){0};
    transform.size = (Vector3){10.0f, 0.5f, 10.0f};
    this->gameObjects.push_back(new StaticMesh(transform, GREEN));

    #if defined(CHAR_GAME_DEBUG)
    TraceLog(LOG_INFO, "Level1 constructor");
    #endif
}

game::Level1::~Level1(void)
{
   for (std::size_t i=0; i < gameObjects.size(); i++)
    {
        delete gameObjects[i];
        gameObjects[i] = nullptr;
    }

    #if defined(CHAR_GAME_DEBUG)
    TraceLog(LOG_INFO, "Level1 destructor");
    #endif
}

void game::Level1::run(void)
{
    this->update();
    this->draw();
}

void game::Level1::update(void)
{
    std::vector<GameObject *>::iterator it = gameObjects.begin();
    for (it; it != gameObjects.end(); it++)
        (*it)->update();
}

void game::Level1::draw(void) 
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

game::SceneType game::Level1::type(void) const
{
    return SceneType::Level_1;
}
