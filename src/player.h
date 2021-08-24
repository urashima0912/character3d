#pragma once
#ifndef __CHAR_PLAYER_H__
#define __CHAR_PLAYER_H__

#include "includes/raylib.h"
#include "includes/game_object.h"
#include "i_camera.h"
#include "../config.h"

namespace game
{
    CHAR_GAME class Player : public GameObject{
        private:
            ICamera *camera;

        public:
            Player(void);
            Player(Vector3 position);
            ~Player(void);

            void update(void) override;
            void draw(void) const override;
            GameObjectType type(void) const override;
            Camera3D getCamera(void) const;
    };
}

#endif //__CHAR_PLAYER_H__