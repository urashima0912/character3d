#include "level1.h"
#include "../player.h"
#include "../static_mesh.h"


game::Level1::Level1(int32_t id)
{
    this->id = id;

    // HideCursor();
    // DisableCursor();

    Vector3 playerPosition = {0.0f, 1.8f, 0.0f};
    this->gameObjects.push_back(new Player(playerPosition));

    // Ground Initilize.
    Transform transform = {0};
    transform.position = (Vector3){0};
    transform.rotation = (Vector3){0};
    transform.size = (Vector3){30.0f, 0.1f, 30.0f};
    Color groundColor = {100, 100, 0, 255};
    this->gameObjects.push_back(new StaticMesh(transform, groundColor));

    // Static Box.
    Transform tBox1 = {0};
    tBox1.position = (Vector3){1.5f, 1.0f, 1.5f};
    tBox1.rotation = (Vector3){0};
    tBox1.size = (Vector3){1.0f, 1.0f, 1.0f};
    StaticMesh *box = new StaticMesh(tBox1, BLUE); //TODO: change this by a unique_ptr
    box->setCollisionShapeEnabled(true);
    box->setCollisionShapeTrigger(true);
    this->gameObjects.push_back(box);

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
    ClearBackground(BLACK);
    #if defined(CHAR_GAME_DEBUG)
        DrawFPS(10, 10);
    #endif

    Player *player = dynamic_cast<Player*>(gameObjects[0]);
    BeginMode3D(player->getCamera());
    
    std::vector<GameObject *>::iterator it = gameObjects.begin();
    for(it; it != gameObjects.end(); it++)
        (*it)->draw();

    

    DrawGrid(NUMBER_SQUARE_GRID, 1.0f);

    // Draw Axis
    DrawLine3D({0}, {15.0f, 0.0f, 0.0f}, RED);
    DrawLine3D({0}, {0.0f, 15.0f, 0.0f}, GREEN);
    DrawLine3D({0}, {0.0f, 0.0f, 15.0f}, BLUE);

    EndMode3D();

    EndDrawing();
}

game::SceneType game::Level1::type(void) const
{
    return SceneType::Level_1;
}
