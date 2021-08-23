#include "i_camera.h"
#include "../config.h"

game::ICamera::ICamera(void)
{
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.position = (Vector3){0.0f, 5.0f, 10.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.projection = CAMERA_CUSTOM;

    #if defined(CHAR_GAME_DEBUG)
    TraceLog(LOG_INFO, "ICamera Contructor");
    #endif
}

game::ICamera::~ICamera()
{
    #if defined(CHAR_GAME_DEBUG)
    TraceLog(LOG_INFO, "ICamera destructor");
    #endif
}

void game::ICamera::update(void) {}

void game::ICamera::draw(void) const {}

GameObjectType game::ICamera::type(void) const
{
    return GameObjectType::Camera3d;
}