/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
         TCS2111 Computer Graphics
Session: Trimester 2, 2015/16
ID and Name #1 : 1141125087 Hii Yong Lian
Contacts    #1 : 016-4111005 yonglian146@gmail.com
ID and Name #2 : 112272848 Lee Zhen Yong
Contacts    #2 : 016-3188854 bruceoutdoors@gmail.com
********************************************/

#include "Selectable.hpp"
#include "WypWindow.hpp"

GLuint Selectable::currentId = 1;
std::map<GLuint, Selectable*> Selectable::idToSelectable;

Selectable::Selectable()
{
    id = currentId++;
    idToSelectable[id] = this;
}

GLuint Selectable::getId() const
{
    return id;
}

void Selectable::drawSelector()
{
    draw();
}

Selectable *Selectable::getSelectable(const GLuint id)
{
    return idToSelectable[id];
}
