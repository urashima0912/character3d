#pragma once
#ifndef __CHAR_SCENE_H__
#define __CHAR_SCENE_H__

#include <vector>
#include "game_object.h"

namespace game
{
    enum SceneType {
        Level_1 = 0,
    };

    class Scene
    {
        protected:
            std::vector<GameObject *> gameObjects;
        
        protected:
            virtual void update(void) = 0;
            virtual void draw(void) = 0;
        
        public:
            virtual ~Scene() {}
            virtual SceneType type(void) const = 0;
            virtual void run(void) = 0;
    };
}

#endif //__CHAR_SCENE_H__