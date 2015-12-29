#pragma once

#include <chrono>

//the main program will call methods from this class
class MyVirtualWorld
{
public:
    MyVirtualWorld();
    virtual ~MyVirtualWorld();

    virtual void draw() {}
    virtual void tickTime() {}

    void calculateElapsedTime();

protected:
    long int elapseTime;

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> timeold, timenew;
};

