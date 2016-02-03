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
class RollerCoaster : public Drawable{
public:
    RollerCoaster();
    void draw() override;
private:
};

#endif /* RollerCoaster_hpp */
