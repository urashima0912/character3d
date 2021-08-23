#pragma once
#ifndef __CHAR_APP_H__
#define __CHAR_APP_H__

#include "../config.h"
#include "scene.h"

namespace game {
    CHAR_GAME class App
    {
        private:
            Scene *currentScene;

        public:
            App(void);
            ~App(void);

            void run(void);

        private:
            void initialize(void);
    };
}


#endif //__CHAR_APP_H__