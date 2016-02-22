/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
         TCS2111 Computer Graphics
Session: Trimester 2, 2015/16
ID and Name #1 : 1141125087 Hii Yong Lian
Contacts    #1 : 016-4111005 yonglian146@gmail.com
ID and Name #2 : 112272848 Lee Zhen Yong
Contacts    #2 : 016-3188854 bruceoutdoors@gmail.com
********************************************/

#ifndef TOWER_H
#define TOWER_H

#include "utilities/Lathe.hpp"
#include "utilities/Drawable.hpp"
#include "utilities/Transformable.hpp"

class Tower : public Drawable, public Transformable
{
    public:
        Tower();
        virtual ~Tower();

        void draw() override;
    protected:
    private:
        Lathe *bottomSec;
        Lathe *topSec;
};

#endif // TOWER_H
