/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
         TCS2111 Computer Graphics
Session: Trimester 2, 2015/16
ID and Name #1 : 1141125087 Hii Yong Lian
Contacts    #1 : 016-4111005 yonglian146@gmail.com
ID and Name #2 : 112272848 Lee Zhen Yong
Contacts    #2 : 016-3188854 bruceoutdoors@gmail.com
********************************************/

#ifndef FERRISMONSTER_H
#define FERRISMONSTER_H

#include "utilities/Drawable.hpp"
#include "Tower.hpp"
#include "CurveTower.hpp"
#include "utilities/Mesh.hpp"

class FerrisMonster : public Drawable, public Transformable
{
public:
    FerrisMonster();
    virtual ~FerrisMonster();

    void draw() override;
protected:
private:
    Tower tower;
    CurveTower ctower;
    Mesh *moon;
};

#endif // FERRISMONSTER_H
