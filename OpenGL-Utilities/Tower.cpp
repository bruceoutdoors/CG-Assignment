/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
         TCS2111 Computer Graphics
Session: Trimester 2, 2015/16
ID and Name #1 : 1141125087 Hii Yong Lian
Contacts    #1 : 016-4111005 yonglian146@gmail.com
ID and Name #2 : 112272848 Lee Zhen Yong
Contacts    #2 : 016-3188854 bruceoutdoors@gmail.com
********************************************/

#include "Tower.hpp"
#include <vector>

using namespace std;

Tower::Tower()
{
    vector<vec2> lpoints =
    {
        {{ 5, 48 }},
        {{ 5, 43 }},
        {{ 6, 39 }},
        {{ 5, 36 }},
        {{ 6, 34 }},
        {{ 7, 32 }},
        {{ 6, 30 }},
        {{ 6, 22 }},
        {{ 7, 17 }},
        {{ 10, 13 }},
        {{ 12, 9 }},
        {{ 10, 4 }},
        {{ 7, 1 }},
        {{ 5, 0 }},
    };
    bottomSec = new Lathe(lpoints, 22);

    lpoints = {
        {{ 0.1, 60 }},
        {{ 1, 58 }},
        {{ 2.5, 56 }},
        {{ 4.5, 54 }},
        {{ 7, 52 }},
        {{ 5, 54 }},
        {{ 4.5, 51 }},
        {{ 5, 48 }},
    };
    topSec = new Lathe(lpoints, 8);
//    setTranslateY(-13);
    setScale(.2);
}

Tower::~Tower()
{
    delete bottomSec;
    delete topSec;
}

void Tower::draw()
{
    applyTransform([&]() {
        glColor3f(0.5, 0.4, 0.8);
        bottomSec->draw();
        glColor3f(.7, .5, .3);
        topSec->draw();
    });
}

