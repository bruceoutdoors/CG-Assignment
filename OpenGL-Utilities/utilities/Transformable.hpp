#pragma once

#include <functional>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include "VecMatMath.hpp"
#include <vector>

class Transformable
{
public:
    Transformable(bool isRotateAlongAxis = false);
    void applyTransform(std::function<void()> drawCall);
    void addTransformation(Transformable *t);
    void applyTransformOnMatrix();

    GLfloat getScale() const;
    vec3 getAxis() const;
    GLfloat getRotateX() const;
    GLfloat getRotateY() const;
    GLfloat getRotateZ() const;
    GLfloat getAxisRotation() const;
    GLfloat getTranslateX() const;
    GLfloat getTranslateY() const;
    GLfloat getTranslateZ() const;

    void setScale(const GLfloat &value);
    void setAxis(const vec3 &value);
    void setRotateX(const GLfloat &value);
    void setRotateY(const GLfloat &value);
    void setRotateZ(const GLfloat &value);
    void setAxisRotation(const GLfloat &value);
    void setTranslate(const vec3 &t);
    void setTranslateX(const GLfloat &value);
    void setTranslateY(const GLfloat &value);
    void setTranslateZ(const GLfloat &value);

    void resetTransformations();

private:
    bool isRotateAlongAxis;
    std::vector<Transformable*> transformations;

    vec3 axis;
    GLfloat axisRotation;

    GLfloat rotateX;
    GLfloat rotateY;
    GLfloat rotateZ;

    GLfloat translateX;
    GLfloat translateY;
    GLfloat translateZ;

    GLfloat scale;
};


