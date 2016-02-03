#pragma once

class Animatable
{
public:
    virtual void updateFrame(int elapsedTime) = 0;
    virtual ~Animatable() {}
};
