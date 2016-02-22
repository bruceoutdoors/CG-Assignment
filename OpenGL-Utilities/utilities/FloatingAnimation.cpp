/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
         TCS2111 Computer Graphics
Session: Trimester 2, 2015/16
ID and Name #1 : 1141125087 Hii Yong Lian
Contacts    #1 : 016-4111005 yonglian146@gmail.com
ID and Name #2 : 112272848 Lee Zhen Yong
Contacts    #2 : 016-3188854 bruceoutdoors@gmail.com
********************************************/

#include "FloatingAnimation.hpp"
#include <cmath>

FloatingAnimation::FloatingAnimation(float speed, float strength) :
    moveInterval(moveInterval), elapsedTimeFromLastMove(0), w(0),
    speed(speed), strength(strength)
{

}

FloatingAnimation::~FloatingAnimation()
{
}

void FloatingAnimation::updateFrame(int elapsedTime)
{
    w += 0.1;
    t.setTranslateY(sin(w * speed) * strength);

    w = fmod(w, (2 * 3.141592 / speed));
}

Transformable *FloatingAnimation::getTransformable()
{
    return &t;
}

