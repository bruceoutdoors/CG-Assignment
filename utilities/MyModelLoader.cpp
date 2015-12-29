#include "mymodelloader.hpp"
#include <fstream>
#include <math.h>

void MyModelLoader::load(string filename, float scale)
{
    int numberOfVertices;
    int numberOfFaces;
    ifstream fin;
    fin.open(filename.c_str());

    if (fin.good())
    {
        fin >> numberOfVertices;
        fin >> numberOfFaces;
        int varraysize = numberOfVertices*3;
        vertices.reserve(varraysize);
        faces.reserve(numberOfFaces*4); //this is just the minimum

        float coord;
        for (int i=0; i<varraysize && fin.good(); i++)
        {
            fin >> coord;
            vertices.push_back(coord*scale);
        }
        int vcount,index;
        for (int i=0; i<numberOfFaces && fin.good(); ++i)
        {
            fin >> vcount;
            faces.push_back(vcount);
            for (int j=0; j<vcount && fin.good(); ++j)
            {
                fin >> index;
                faces.push_back(index);
            }
        }
        fin.close();
    }

    vector<int>::iterator itr;
    GLfloat normal[3];

    stanforddragon = glGenLists(1);
    glNewList(stanforddragon, GL_COMPILE);
    glColor3f(1.0f, 0.8f, 0.4f);
    int vcount;  //number of vertices for a particular polygon
    for (itr = faces.begin(); itr!=faces.end();)
    {
        vcount = *itr;
        itr++;
        int i1, i2, i3;
        i1 = (*itr)     * 3;
        i2 = (*(itr+1)) * 3;
        i3 = (*(itr+2)) * 3;
        computeSurfaceNormal( &vertices[i1],&vertices[i2],&vertices[i3],
                              normal );
        glBegin(GL_POLYGON);
        glNormal3fv(normal);
        for (int k=0; k<vcount; k++)
        {
            glVertex3fv( &vertices[(*itr)*3] );
            itr++;
        }
        glEnd();
    }
    glEndList();
}

void MyModelLoader::draw()
{
    glCallList(stanforddragon);
}

void MyModelLoader::computeSurfaceNormal( GLfloat vertex1[],
        GLfloat vertex2[],
        GLfloat vertex3[],
        GLfloat normal[])
{
    GLfloat v1[3], v2[3];
    v1[0] = vertex3[0] - vertex2[0];
    v1[1] = vertex3[1] - vertex2[1];
    v1[2] = vertex3[2] - vertex2[2];
    v2[0] = vertex1[0] - vertex2[0];
    v2[1] = vertex1[1] - vertex2[1];
    v2[2] = vertex1[2] - vertex2[2];
    normal[0] = v1[1]*v2[2] - v1[2]*v2[1];
    normal[1] = v1[2]*v2[0] - v1[0]*v2[2];
    normal[2] = v1[0]*v2[1] - v1[1]*v2[0];
    GLfloat magnitude = sqrt(   normal[0]*normal[0]
                                + normal[1]*normal[1]
                                + normal[2]*normal[2] );
    normal[0] /= magnitude;
    normal[1] /= magnitude;
    normal[2] /= magnitude;
}
