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
