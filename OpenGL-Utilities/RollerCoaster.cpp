//
//  RollerCoaster.cpp
//  OpenGL-Utilities-XCODE
//
//  Created by Yong Lian Hii on 02/02/2016.
//  Copyright © 2016 Yong Lian Hii. All rights reserved.
//

#include "RollerCoaster.hpp"
#include "utilities/VecMatMath.hpp"
#include "utilities/Loft.hpp"
#include <vector>
#include <iostream>
#include <random>
RollerCoaster::RollerCoaster() {
    spline = generateSpline(-25, 25, 150,
                                 [](float z)->float { return 0; },
                                 [](float x)->float { return x * 5; },
                                 [](float y)->float { return (sin(y/2.0) * 15) + 20; });
    std::vector<vec2> shape = { {{0,0}}, {{0,10}} };
    loft = new Loft(shape,spline);

}
void RollerCoaster::draw() {




    loft->draw();



}
void RollerCoaster::drawHighlight() {
    std::cout << "IM BEING CLIEKD" << std::endl;
    static vec3 white = {{ 1, 1, 1 }};
    glColor3fv(&white[0]);
    
    GLboolean lightingIsOn;
    glGetBooleanv(GL_LIGHTING, &lightingIsOn);
    glDisable(GL_LIGHTING);
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glLineWidth(1.5f);
    draw();
    glLineWidth(1);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    if (lightingIsOn == GL_TRUE) glEnable(GL_LIGHTING);
}
