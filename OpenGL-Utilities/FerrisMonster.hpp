#ifndef FERRISMONSTER_H
#define FERRISMONSTER_H

#include "utilities/Drawable.hpp"
#include "Tower.hpp"
#include "CurveTower.hpp"
#include "utilities/Mesh.hpp"

class FerrisMonster : public Drawable
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
