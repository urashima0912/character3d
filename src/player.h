#pragma once
#ifndef __CHAR_PLAYER_H__
#define __CHAR_PLAYER_H__

#include "includes/raylib.h"
#include "includes/game_object.h"
#include "i_camera.h"
#include "collision_shape.h"
#include "../config.h"

namespace game
{
    CHAR_GAME class Player : public GameObject{
        private:
            std::unique_ptr<ICamera> camera;
            std::unique_ptr<CollisionShape> collisionShape;
            const float angleVelocity{7.5f};
            const float speed{0.2};

        public:
            Player(void);
            Player(Vector3 position);
            ~Player(void);
            void update(void) override;
            void draw(void) const override;
            GameObjectType type(void) const override;
            Camera3D getCamera(void) const;
        
            bool checkCollision(Transform transform) const;

        private:
            void movement(void);
    };
}

#endif //__CHAR_PLAYER_H__