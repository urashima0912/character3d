#pragma once
#ifndef __CHAR_TRANSFORM_H__
#define __CHAR_TRANSFORM_H__

#include "raylib.h"

namespace game
{
    class Transform
    {
        public:
            Vector3 position{0};
            Vector3 rotation{0};
            Vector3 size{0};
    };
}

#endif //__CHAR_TRANSFORM_H__