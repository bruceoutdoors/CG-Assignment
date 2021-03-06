/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
         TCS2111 Computer Graphics
Session: Trimester 2, 2015/16
ID and Name #1 : 1141125087 Hii Yong Lian
Contacts    #1 : 016-4111005 yonglian146@gmail.com
ID and Name #2 : 112272848 Lee Zhen Yong
Contacts    #2 : 016-3188854 bruceoutdoors@gmail.com
********************************************/

#include "Mesh.hpp"
#include "ObjReader.hpp"

static const vec3 DEFAULT_COLOR = {.5,.5,.5};

Mesh::Mesh() :
    isVertexColor(false),
    isFlatColor(true),
    isVisible(true),
    name("Default Mesh Name"),
    isTextured(false),
    texture(nullptr)
{
    resetTransformations();
}

Mesh::Mesh(std::string path) : Mesh()
{
    ObjReader::loadOBJIndexed(path.c_str(),
                              vertices,
                              uvs,
                              normals,
                              indices);
}

Mesh::~Mesh()
{
    if (texture != nullptr) { delete texture; }
}

void Mesh::draw()
{
    if (!isVisible) return;

    applyTransform(
       [&]() {
           if (isFlatColor) glColor3fv(&flat_color[0]);

           if (isTextured) {
               glColor3f(1, 1, 1);
               texture->use();
               glEnable(GL_TEXTURE_2D);
           }

           glBegin(GL_TRIANGLES);
            for (int j = 0; j < indices.size(); j++) {
                GLushort i = indices[j];
                if (isVertexColor) glColor3fv(&colors[i][0]);
                if (isTextured)    glTexCoord2fv(&uvs[i][0]);
                glNormal3fv(&normals[i][0]);
                glVertex3fv(&vertices[i][0]);
            }
            glEnd();

            if (isTextured) { glDisable(GL_TEXTURE_2D); }
        }
    );
}

void Mesh::drawHighlight()
{
    static vec3 white = {{ 1, 1, 1 }};
    glColor3fv(&white[0]);

    GLboolean lightingIsOn;
    glGetBooleanv(GL_LIGHTING, &lightingIsOn);
    glDisable(GL_LIGHTING);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    disableTexture();
    glLineWidth(1.5f);
    draw();
    glLineWidth(1);
    enableTexture();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    if (lightingIsOn == GL_TRUE) glEnable(GL_LIGHTING);
}


bool Mesh::getVisibility() const
{
    return isVisible;
}

void Mesh::setVisibility(bool value)
{
    isVisible = value;
}

std::string Mesh::getName() const
{
    return name;
}

void Mesh::setName(const std::string &value)
{
    name = value;
}

GLuint Mesh::getNumIndices() const
{
    return indices.size();
}

GLuint Mesh::getNumVertices() const
{
    return vertices.size();
}

void Mesh::enableVertexColor()
{
    isVertexColor = true;
}

void Mesh::disableVertexColor()
{
    isVertexColor = false;
}

bool Mesh::hasVertexColor() const
{
    return isVertexColor;
}

void Mesh::enableFlatColor()
{
    isFlatColor = true;
}

void Mesh::disableFlatColor()
{
    isFlatColor = false;
}

bool Mesh::hasFlatColor() const
{
    return isFlatColor;
}

void Mesh::setFlatColor(const vec3 &color)
{
    flat_color = color;
}

bool Mesh::hasUv() const
{
    return !uvs.empty();
}

void Mesh::setTexture(const std::string &path)
{
    texture = new Texture(path);
    enableTexture();
}

bool Mesh::hasTexture() const
{
    return isTextured;
}

void Mesh::enableTexture()
{
    isTextured = true;
}

void Mesh::disableTexture()
{
    isTextured = false;
}
