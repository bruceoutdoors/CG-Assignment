#pragma once

#include "utilities/MyVirtualWorld.hpp"
#include "utilities/Mesh.hpp"
#include "utilities/MyModelLoader.hpp"
#include "utilities/WypWindow.hpp"
#include "utilities/Animatable.hpp"
#include "utilities/AnimationMaster.hpp"
#include <string>
#include <vector>

class SimpleBouncingBall : public Animatable
{
public:
    SimpleBouncingBall();
    void draw() override;
    void updateFrame(int elapsedTime) override;

private:
    long int timetick;
    float vel0;
    float accel;
    float y;
};

class AnimTestWorld : public MyVirtualWorld
{
public:
    AnimTestWorld(WypWindow *parent);
    virtual ~AnimTestWorld();
    void draw() override;

private:
    SimpleBouncingBall simplebouncingball;
    AnimationMaster *am;
    WypWindow *parent;
};
