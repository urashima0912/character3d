#pragma once
#include "includes/raylib.h"
#include "includes/game_object.h"
#include "../config.h"
namespace game
{

    enum MouseDirection
    {
        Left = 0,
        Right,
        None
    };

    CHAR_GAME class ICamera : public GameObject
    {
        private:
            int32_t prevMousePos;

        public:
            Camera3D camera;
            ~ICamera();
        public:
            ICamera(void);

            void update(void) override;
            void draw(void) const override;
            GameObjectType type(void) const override;
            int32_t mouseDirection(void);
    };
}