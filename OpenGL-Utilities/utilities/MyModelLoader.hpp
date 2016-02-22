/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
         TCS2111 Computer Graphics
Session: Trimester 2, 2015/16
ID and Name #1 : 1141125087 Hii Yong Lian
Contacts    #1 : 016-4111005 yonglian146@gmail.com
ID and Name #2 : 112272848 Lee Zhen Yong
Contacts    #2 : 016-3188854 bruceoutdoors@gmail.com
********************************************/

#ifndef MYMODELLOADER_H
#define MYMODELLOADER_H

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include <string>
#include <vector>

using namespace std;

class MyModelLoader
{
 public:
    //load a model and scale it
    void load(string filename, float scale = 1.0);
    void draw();

 private:
    void computeSurfaceNormal( GLfloat vertex1[], GLfloat vertex2[], GLfloat vertex3[], GLfloat normal[]);

    vector<GLfloat> vertices;
    vector<int> faces;
    GLuint stanforddragon; //for generating display list
};

#endif // MYMODELLOADER_H
