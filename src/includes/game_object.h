#pragma once
#ifndef __CHAR_GAME_OBJECT_H__
#define __CHAR_GAME_OBJECT_H__

#include "transform.h"

enum GameObjectType {
    Player = 0,
    StaticMesh,
    Camera3d,
    Scene,
};

namespace game
{
    class GameObject
    {
        public:
            Transform transform;
        
        public:
            virtual ~GameObject() {};
            virtual void update(void) = 0;
            virtual void draw(void) const = 0;
            virtual GameObjectType type(void) const = 0;
    };
}

#endif //__CHAR_GAME_OBJECT_H__