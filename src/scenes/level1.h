#pragma once
#include "../includes/scene.h"
#include "../../config.h"

namespace game
{
    CHAR_GAME class Level1 : public Scene
    {
        private:
            int32_t id;

        public:
            Level1(int32_t id);
            ~Level1(void);
            SceneType type(void) const override;
            void run(void) override;
        
        protected:
            void update(void) override;
            void draw(void) override;
    };
}