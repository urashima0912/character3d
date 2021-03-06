#pragma once
#ifndef __CHAR_COLLISION_SHAPE_H__
#define __CHAR_COLLISION_SHAPE_H__

#include "../config.h"
#include "includes/game_object.h"

namespace game
{
    enum CollisionShapeType
    {
        Empty= 0,
        Rectangle,
    };

    CHAR_GAME class CollisionShape : public GameObject
    {
        public:
            bool isEnabled{false};
            bool isTrigger{false};

        private:
            CollisionShapeType shapeType{CollisionShapeType::Empty};
            Transform transform{0};

        public:
            CollisionShape(CollisionShapeType shapeType, Transform transform);
            ~CollisionShape(void);
            virtual void update(void);
            virtual void draw(void) const;
            virtual GameObjectType type(void) const;

            void setTransform(Transform transform);

            bool checkCollisionCube(const Transform& transform1, const Transform& transform2) const;


        private:
            //TODO: I need to define all shape for colliders.
            void drawRectangleShape(void) const;

    };
}

#endif //__CHAR_COLLISION_SHAPE_H__