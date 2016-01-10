#include "Transformable.hpp"

Transformable::Transformable(bool isRotateAlongAxis) :
    isRotateAlongAxis(isRotateAlongAxis)
{
    resetTransformations();
}


void Transformable::applyTransform(std::function<void()> drawCall)
{
    glPushMatrix();


    for (auto t = transformations.rbegin(); t != transformations.rend(); t++) {
        (*t)->applyTransformOnMatrix();
    }
    applyTransformOnMatrix();

    drawCall();

    glPopMatrix();
}

void Transformable::applyTransformOnMatrix()
{
    glTranslatef(translateX, translateY, translateZ);
    if (isRotateAlongAxis) {
        glRotatef(axisRotation, axis[0], axis[1], axis[2]);
    } else {
        glRotatef(rotateX, 1.0f, 0.0f, 0.0f);
        glRotatef(rotateY, 0.0f, 1.0f, 0.0f);
        glRotatef(rotateZ, 0.0f, 0.0f, 1.0f);
    }

    glScalef(scale, scale, scale);
}

void Transformable::addTransformation(Transformable *t)
{
    transformations.push_back(t);
}

void Transformable::resetTransformations()
{
    axisRotation
      = rotateX
        = rotateY
          = rotateZ
            = translateX
              = translateY
                = translateZ = 0;

    axis = {{ 0, 1, 0 }};
    scale = 1;
}

GLfloat Transformable::getScale() const
{
    return scale;
}

void Transformable::setScale(const GLfloat &value)
{
    scale = value;
}

GLfloat Transformable::getRotateX() const
{
    return rotateX;
}

void Transformable::setRotateX(const GLfloat &value)
{
    rotateX = value;

}
GLfloat Transformable::getRotateY() const
{
    return rotateY;
}

void Transformable::setRotateY(const GLfloat &value)
{
    rotateY = value;

}
GLfloat Transformable::getRotateZ() const
{
    return rotateZ;
}

void Transformable::setRotateZ(const GLfloat &value)
{
    rotateZ = value;
}

void Transformable::setTranslate(const vec3 &t)
{
    translateX = t[0];
    translateY = t[1];
    translateZ = t[2];
}

GLfloat Transformable::getTranslateX() const
{
    return translateX;
}

void Transformable::setTranslateX(const GLfloat &value)
{
    translateX = value;

}

GLfloat Transformable::getTranslateY() const
{
    return translateY;
}

void Transformable::setTranslateY(const GLfloat &value)
{
    translateY = value;

}
GLfloat Transformable::getTranslateZ() const
{
    return translateZ;
}

void Transformable::setTranslateZ(const GLfloat &value)
{
    translateZ = value;
}

vec3 Transformable::getAxis() const
{
    return axis;
}

GLfloat Transformable::getAxisRotation() const
{
    return axisRotation;
}

void Transformable::setAxis(const vec3& value)
{
    axis = value;
}

void Transformable::setAxisRotation(const GLfloat& value)
{
    axisRotation = value;
}
