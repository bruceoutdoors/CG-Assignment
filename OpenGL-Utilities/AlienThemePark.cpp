#include "AlienThemePark.hpp"
#include <iostream>

using namespace std;

AlienThemePark::AlienThemePark(WypWindow *wypwindow) :
    MyVirtualWorld(wypwindow),
    activeSelect(nullptr),
    spaceship("data/dark_fighter_6.obj"),
    spaceCruiser("data/space_cruiser_4.obj"),
    elephant("data/elephant-triangulated.obj")
{
    spline = generateSpline(-25, 10, 150,
                            [](float z)->float { return sin(z/2.0) * 15; },
                            [](float x)->float { return cos(x/2.0) * 15; },
                            [](float y)->float { return y + 20; });
    
    coaster_spline = generateSpline(-25, 25, 150,
                            [](float z)->float { return 0; },
                            [](float x)->float { return x * 5; },
                            [](float y)->float { return (sin(y/2.0) * 15) + 30; });

    sa = new SplineAnimation(&spline, 10);
    rollercoaster_animation = new SplineAnimation(&coaster_spline, 10);
    
    fa = new FloatingAnimation(1.2, .6);

    spaceship.setFlatColor({{.9, .3, .9}});
    spaceship.disableFlatColor();
    spaceship.setRotateZ(-90);
    spaceship.addTransformation(rollercoaster_animation->getTransformable());
    spaceship.setTexture("data/dark_fighter_6_color.png");

    spaceCruiser.setTexture("data/space_cruiser_4_color.png");
    spaceCruiser.setName("Space Cruiser");
    spaceCruiser.disableFlatColor();
    spaceCruiser.addTransformation(fa->getTransformable());
    spaceCruiser.setScale(.5);
    spaceCruiser.setTranslateZ(25);
    spaceCruiser.setTranslateY(10);

    elephant.setTexture("data/elephant-texture-1024.jpg");
    elephant.setName("Gook the elephant");
    elephant.disableFlatColor();
    elephant.setTranslateX(20);
    elephant.setTranslateZ(25);
    
//    ferrismonster.addTransformation(rollercoaster_animation->getTransformable());
//    ferrismonster.setRotateY(90);
//    ferrismonster.setRotateX(180);

//    am.addAnimatable(sa);
    am.addAnimatable(fa);
    am.addAnimatable(rollercoaster_animation);

    SelectMaster *sm = wypwindow->getSelectMaster();
    sm->addSelectable(&spaceCruiser);
    sm->addSelectable(&spaceship);
    sm->addSelectable(&elephant);
    sm->addSelectable(&rollercoaster);


    wypwindow->getOnSelectSignal()->connect([&](Selectable *s)
    {
        Mesh *m = dynamic_cast<Mesh*>(s);
        if (m != nullptr) {
            activeSelect = m;
            cout << "Mesh Selected: " << m->getName() << endl;
        } else {
            activeSelect = nullptr;
        }

    });

    wypwindow->getOnSpecialSignal()->connect([&](int key)
    {
        if (activeSelect == nullptr) return;

        switch(key) {
        case GLUT_KEY_DOWN  :
            activeSelect->setTranslateX(activeSelect->getTranslateX() + .5);
            break;
        case GLUT_KEY_UP    :
            activeSelect->setTranslateX(activeSelect->getTranslateX() - .5);
            break;
        case GLUT_KEY_LEFT  :
            activeSelect->setTranslateZ(activeSelect->getTranslateZ() + .5);
            break;
        case GLUT_KEY_RIGHT :
            activeSelect->setTranslateZ(activeSelect->getTranslateZ() - .5);
            break;
        }
    });

    wypwindow->getOnKeyboardSignal()->connect([&](unsigned char c)
    {
        cout << c;
    });

    wypwindow->getOnMouseSignal()->connect(
        [&](int button, int state, int x, int y)
    {
        if (state == GLUT_UP) {
            cout << "click: " << x << " " << y << endl;
        }
    });
}

AlienThemePark::~AlienThemePark()
{
    delete sa;
    delete fa;
}

void AlienThemePark::draw()
{
    am.update();

    glPushMatrix();

    GLboolean lightingIsOn;
    glGetBooleanv(GL_LIGHTING, &lightingIsOn);
    glDisable(GL_LIGHTING);

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    for (int i = 0; i < spline.size()-1; i++) {
        glVertex3fv(&spline[i][0]);
        glVertex3fv(&spline[i+1][0]);
    }
    glEnd();

    if (lightingIsOn) glEnable(GL_LIGHTING);
    glPopMatrix();

    glPushMatrix();
        spaceship.draw();
        spaceCruiser.draw();
        elephant.draw();

        if (activeSelect != nullptr) activeSelect->drawHighlight();

    glPopMatrix();

    ferrismonster.draw();
    rollercoaster.draw();

    glColor3f(0.5, 0.6, .8);
    glBegin(GL_QUADS);
    glVertex3f(-50, 0, -50);
    glVertex3f(-50, 0, 50);
    glVertex3f(50, 0, 50);
    glVertex3f(50, 0, -50);
    glEnd();
    
    glTranslatef(0,200,0);
    spotlights.draw();
}

void AlienThemePark::setupLights() {
    glEnable(GL_LIGHTING);
    //GL_COLOR_MATERIAL
    //  * relevant only if lighting is enabled
    //  * disabled by default
    //  * if enabled,glColor*(...) is in effect to change the color tracked by glColorMaterial
    //  (meaning that in our case here, glColor*(...) affect the diffuse color of the frant face) glMaterial*(...) is in effect to change the color glColor*(...) will not work!
    // * if disbled,
    //
    //glColor*(...) always in effect if lighting is not enabled
    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    //ensure unit vectors remain unit vectors after
    // modelview scaling
    glEnable(GL_NORMALIZE);
    
    spotlights.setupLights();
//    myswinglights.setupLights();
    //define the color of light, i.e. LIGHT0
    GLfloat mycolor[] = { 0.15, 0.15, 0.15};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, mycolor);
    //enable the light, i.e. LIGHT0
    glEnable(GL_LIGHT0);
//    for (int i=0; i<6; ++i)
//        lighton[i] = true;
}
