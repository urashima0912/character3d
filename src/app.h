#pragma once
#ifndef __CHAR_APP_H__
#define __CHAR_APP_H__

#include <vector>
#include "../config.h"
#include "player.h"
#include "i_camera.h"

namespace game {
    CHAR_GAME class App
    {
        private:
            std::vector<GameObject *> objects;
         
        public:
            App(void);
            ~App(void);

            void run(void);

        private:
            void initialize(void);
            void draw(void);
            void update(void);
    };
}


#endif //__CHAR_APP_H__