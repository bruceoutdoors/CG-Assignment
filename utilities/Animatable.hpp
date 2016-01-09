#pragma once

#include "Drawable.hpp"

class Animatable : public Drawable
{
public:
    virtual void updateFrame(int elapsedTime) = 0;
};
