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

