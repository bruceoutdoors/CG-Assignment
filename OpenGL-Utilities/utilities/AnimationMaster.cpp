#include "AnimationMaster.hpp"
#include "Animatable.hpp"

#include <algorithm>

AnimationMaster::AnimationMaster(int framePerSec)
{
    milliSecPerFrame = 1000 / framePerSec;
    elapsedTime = 0;
    timeold = std::chrono::high_resolution_clock::now();
}

void AnimationMaster::addAnimatable(Animatable* anim)
{
    anims.push_back(anim);
}

void AnimationMaster::removeAnimatable(Animatable* anim)
{
    auto rf = std::remove_if(anims.begin(), anims.end(),
                            [&](Animatable *x){ return anim == x; });
    if (rf != anims.end()) anims.erase(rf);
}

void AnimationMaster::update()
{
    timenew    = std::chrono::high_resolution_clock::now();
    elapsedTime += std::chrono::duration_cast<std::chrono::milliseconds>(timenew - timeold).count();
    timeold    = timenew;

    if (elapsedTime >= milliSecPerFrame) {
        updateAnimFrames();
        elapsedTime = 0;
    }
}

void AnimationMaster::updateAnimFrames()
{
    for (auto anim : anims) anim->updateFrame(elapsedTime);
}
