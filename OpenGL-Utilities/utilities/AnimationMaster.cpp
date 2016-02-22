/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
         TCS2111 Computer Graphics
Session: Trimester 2, 2015/16
ID and Name #1 : 1141125087 Hii Yong Lian
Contacts    #1 : 016-4111005 yonglian146@gmail.com
ID and Name #2 : 112272848 Lee Zhen Yong
Contacts    #2 : 016-3188854 bruceoutdoors@gmail.com
********************************************/

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
void AnimationMaster::addAnimatable(Animatable &anim)
{
    anims.push_back(&anim);
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
