//
//  RollerCoaster.cpp
//  OpenGL-Utilities-XCODE
//
//  Created by Yong Lian Hii on 02/02/2016.
//  Copyright © 2016 Yong Lian Hii. All rights reserved.
//

#include "RollerCoaster.hpp"
#include "VecMatMath.hpp"
#include "Loft.hpp"
#include <vector>
#include <iostream>
#include <random>
RollerCoaster::RollerCoaster() {
    
}
void RollerCoaster::draw() {
    
    auto spline = generateSpline(-25, 25, 150,
                            [](float z)->float { return sin(z/2.0) * 15; },
                            [](float x)->float { return cos(x/2.0) * 15; },
                            [](float y)->float { return y; });
    std::vector<vec2> shape = { {0,0} , {2,2}, {4,4}};
    
    auto loft = new Loft(shape,spline);
    loft->draw();
    
    
    
}
