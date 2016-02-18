#include "FerrisMonster.hpp"

FerrisMonster::FerrisMonster()
{
    moon = new Mesh("data/moon.obj");
    moon->setScale(6.0);
    moon->setTranslateY(1);
    moon->setRotateX(-20);
    moon->setFlatColor({{ .8, .7, .6 }});
}

FerrisMonster::~FerrisMonster()
{
    delete moon;
}

void FerrisMonster::draw()
{
    
    applyTransform(
                   [&]() {

    glPushMatrix();
    glTranslatef(3, -2, 1);
    tower.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3, 0, 1);
    tower.draw();
    glPopMatrix();

    glPushMatrix();
    glScalef(2,2,2);
    glTranslatef(.5, 0, -2);
    tower.draw();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.8,1.8,1.8);
    glTranslatef(-.5, -1, 2);
    tower.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4, 0, -2);
    ctower.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4, 0, -2);
    glScalef(1.5,1.5,1.5);
    ctower.draw();
    glPopMatrix();

    glPushMatrix();
    moon->draw();
    glPopMatrix();
                   }
                   );
}
