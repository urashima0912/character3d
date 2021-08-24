#pragma once
#include "includes/raylib.h"
#include "includes/game_object.h"
#include "../config.h"
namespace game
{
    CHAR_GAME class ICamera : public GameObject
    {
        public:
            Camera3D camera;
            ~ICamera();
        public:
            ICamera(void);

            void update(void) override;
            void draw(void) const override;
            GameObjectType type(void) const override;
    };
}