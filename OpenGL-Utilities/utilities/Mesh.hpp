#pragma once

#include "VecMatMath.hpp"
#include "Transformable.hpp"
#include "Selectable.hpp"
#include "Texture.hpp"
#include <vector>
#include <string>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

using std::vector;

class Mesh : public Transformable, public Selectable
{
public:
    Mesh();
    Mesh(std::string path);
    virtual ~Mesh();
    void draw() override;
    void drawHighlight() override;

    GLuint getNumIndices() const;
    GLuint getNumVertices() const;

    void enableVertexColor();
    void disableVertexColor();
    bool hasVertexColor() const;

    void enableFlatColor();
    void disableFlatColor();
    bool hasFlatColor() const;
    void setFlatColor(const vec3 &color);

    bool hasUv() const;

    void setTexture(const std::string &path);
    bool hasTexture() const;
    void enableTexture();
    void disableTexture();

    bool getVisibility() const;
    void setVisibility(bool value);

    std::string getName() const;
    void setName(const std::string &value);

protected:
    vector<vec3> vertices;
    vector<vec3> colors;
    vector<vec3> normals;
    vector<vec2> uvs;
    vector<GLushort> indices;

private:
    bool isVertexColor;
    bool isFlatColor;
    bool isVisible;
    bool isTextured;
    std::string name;

    vec3 flat_color;
    Texture *texture;
};

