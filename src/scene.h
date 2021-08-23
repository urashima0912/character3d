#pragma once

#include <vector>
#include "includes/game_object.h"


namespace game
{
    class Scene
    {
        private:
            int id;
            std::vector<GameObject *> gameObjects;

        public:
            Scene(int id);
            ~Scene(void);

            void run(void);

        private:
            void update(void);
            void draw(void);
    };
}