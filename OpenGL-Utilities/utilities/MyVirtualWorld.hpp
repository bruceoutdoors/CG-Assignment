#pragma once
#include "Signal.hpp"

class WypWindow;

class MyVirtualWorld
{
public:
    MyVirtualWorld(WypWindow *wypwindow);
    virtual ~MyVirtualWorld();

    virtual void draw() {}

protected:
    WypWindow *wypwindow;
};

