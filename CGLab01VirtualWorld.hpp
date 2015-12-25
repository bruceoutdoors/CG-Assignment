#pragma once

#include "wyp/MyVirtualWorld.hpp"
#include "wyp/MyModelLoader.hpp"
#include "utilities/Mesh.hpp"
#include <string>
#include <vector>

class SimplePolygon
{
public:
    void draw();
};

class SimpleTriangles
{
public:
    void draw();
};

class SimpleBox
{
public:
    void draw();
};

class SimpleTeapot
{
public:
    void draw();
};

class SimpleBouncingBall
{
public:
    SimpleBouncingBall();
    void draw();
    void tickTime(long int elapseTime);
private:
    long int timetick;
    float vel0;
    float accel;
};

class CGLab01VirtualWorld : public MyVirtualWorld
{
public:
    CGLab01VirtualWorld();
    virtual ~CGLab01VirtualWorld();
    void draw() override;
    void tickTime() override;

private:
    SimplePolygon      simplepolygon;
    SimpleBox          simplebox;
    SimpleTriangles    simpletriangles;
    SimpleTeapot       simpleteapot;
    SimpleBouncingBall simplebouncingball;
    MyModelLoader      mymodelloader;
    Mesh *deer;
    Mesh *elephant;
};
