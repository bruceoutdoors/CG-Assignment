/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
         TCS2111 Computer Graphics
Session: Trimester 2, 2015/16
ID and Name #1 : 1141125087 Hii Yong Lian
Contacts    #1 : 016-4111005 yonglian146@gmail.com
ID and Name #2 : 112272848 Lee Zhen Yong
Contacts    #2 : 016-3188854 bruceoutdoors@gmail.com
********************************************/

//
//  Loft.hpp
//  OpenGL-Utilities-XCODE
//
//  Created by Yong Lian Hii on 30/12/2015.
//  Copyright © 2015 Yong Lian Hii. All rights reserved.
//

#ifndef Loft_hpp
#define Loft_hpp

#include "VecMatMath.hpp"
#include <vector>
#include "Animatable.hpp"
#include "Drawable.hpp"
#include "Selectable.hpp"

class Loft : public Selectable {
public:
    Loft(const std::vector<vec2> &points, const std::vector<vec3> &path);
    void init();
    void draw();

private:
    const std::vector<vec2> &points2d;
    std::vector<vec3> directions;
    const std::vector<vec3> &path;
    std::vector<std::vector<vec3> > points3d;
    std::vector<vec3> splines;
};


#endif /* Loft_hpp */
