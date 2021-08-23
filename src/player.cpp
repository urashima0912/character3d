#include "player.h"

game::Player::Player(void) : GameObject()
{
    camera = new ICamera();

    transform.size = (Vector3) {1.0f, 2.0f, 1.0f};
    transform.position = (Vector3){0.0f, transform.size.y / 2, 0.0f};
    transform.rotation = (Vector3){0};
    #if defined(CHAR_GAME_DEBUG)
    TraceLog(LOG_INFO, "Player contructor.");
    #endif
}

game::Player::~Player(void)
{
    delete camera;
    camera = nullptr;
    // camera = nullptr;
    #if defined(CHAR_GAME_DEBUG)
    TraceLog(LOG_INFO, "Player destructor.");
    #endif
}

void game::Player::update(void)
{
    camera->update();
}

void game::Player::draw(void) const
{
    camera->draw(); //TODO: Implement GUI.

    DrawCube(
        transform.position,
        transform.size.x,
        transform.size.y,
        1.0f,
        RED
    );
    DrawCubeWires(
        transform.position,
        transform.size.x,
        transform.size.y,
        1.0f,
        RAYWHITE
    );
}

GameObjectType game::Player::type(void) const
{
    return GameObjectType::Player;
}

Camera3D game::Player::getCamera(void) const
{
    return camera->camera;
}