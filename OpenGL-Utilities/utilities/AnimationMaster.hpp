/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
         TCS2111 Computer Graphics
Session: Trimester 2, 2015/16
ID and Name #1 : 1141125087 Hii Yong Lian
Contacts    #1 : 016-4111005 yonglian146@gmail.com
ID and Name #2 : 112272848 Lee Zhen Yong
Contacts    #2 : 016-3188854 bruceoutdoors@gmail.com
********************************************/

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
