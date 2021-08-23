#pragma once

#include "../config.h"
#include "includes/game_object.h"

namespace game
{
    CHAR_GAME class StaticMesh : public GameObject
    {   
        public:
            Color color;

        public:
            StaticMesh(Transform transform, Color color);
            ~StaticMesh(void);

            void update(void) override;
            void draw(void) const override;
            GameObjectType type(void) const override;
    };
}