//
//  RollerCoaster.hpp
//  OpenGL-Utilities-XCODE
//
//  Created by Yong Lian Hii on 02/02/2016.
//  Copyright © 2016 Yong Lian Hii. All rights reserved.
//

#ifndef RollerCoaster_hpp
#define RollerCoaster_hpp
#include "utilities/Drawable.hpp"
#include "utilities/Selectable.hpp"
#include "utilities/VecMatMath.hpp"
#include "utilities/Loft.hpp"
#include <vector>
class RollerCoaster : public Selectable{
public:
    RollerCoaster();
    void draw() override;
    void drawHighlight();
private:
    std::vector< vec3 > spline;
    std::vector< vec3 > spline2;
    Loft* loft;
};

#endif /* RollerCoaster_hpp */
