#pragma once
#ifndef __CHAR_TRANSFORM_H__
#define __CHAR_TRANSFORM_H__

#include "raylib.h"

namespace game
{
    class Transform
    {
        public:
            Vector3 position;
            Vector3 rotation;
            Vector3 size;
    };
}

#endif //__CHAR_TRANSFORM_H__