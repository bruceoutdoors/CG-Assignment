#pragma once

#include <vector>
#include <chrono>

class Animatable;

class AnimationMaster
{
public:
    AnimationMaster(int framePerSec = 60);
    void update();
    void addAnimatable(Animatable *anim);
    void addAnimatable(Animatable &anim);
    void removeAnimatable(Animatable* anim);

private:
    void updateAnimFrames();

    int milliSecPerFrame;
    int elapsedTime;
    std::vector<Animatable*> anims;
    std::chrono::time_point<std::chrono::high_resolution_clock> timeold, timenew;
};
