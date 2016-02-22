/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
         TCS2111 Computer Graphics
Session: Trimester 2, 2015/16
ID and Name #1 : 1141125087 Hii Yong Lian
Contacts    #1 : 016-4111005 yonglian146@gmail.com
ID and Name #2 : 112272848 Lee Zhen Yong
Contacts    #2 : 016-3188854 bruceoutdoors@gmail.com
********************************************/

#include "CurveTower.hpp"
#include <vector>

using namespace std;

CurveTower::CurveTower()
{
    vector<vec3> pp = generateSpline(-1.25, 0.8, 8,
                                     [](float z)->float { return 0; },
                                     [](float x)->float { return x * 50; },
                                     [](float y)->float { return (exp(y) * sin(2*M_PI*y) + 5) * 2; });


    vector<vec2> lpoints;

    for (auto &p : pp)
    {
        lpoints.push_back({{ p[1], p[0]}});
    }

    bottomSec = new Lathe(lpoints, 8);

    pp = generateSpline(0.8, 1.7, 15,
                        [](float z)->float { return 0; },
                        [](float x)->float { return x * 50; },
                        [](float y)->float { return (exp(y) * sin(2*M_PI*y) + 5) * 2; });
    lpoints.clear();
    for (auto &p : pp)
    {
        lpoints.push_back({{ p[1], p[0]}});
    }
    topSec = new Lathe(lpoints, 8);
    setTranslateY(5);
    setScale(.1);
}

CurveTower::~CurveTower()
{
    delete bottomSec;
    delete topSec;
}

void CurveTower::draw()
{
    applyTransform([&]()
    {
        glColor3f(0.5, 0.4, 0.8);
        bottomSec->draw();
        glColor3f(.7, .5, .3);
        topSec->draw();
    });
}

