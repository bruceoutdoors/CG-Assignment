/*
 TGD2151 Computer Graphics Fundamentals
 Faculty of Computing & Informatics, Multimedia University

 CGLab01.hpp

 Objective: Header File for Lab01 Demo Models / World

 (C) 2006-2015 Ya Ping Wong, All Rights Reserved.
 http://wongyaping.com

 Stanford Dragon:
 Original Model : Copyright by Stanford University
 http://graphics.stanford.edu/data/3Dscanrep/
 Low-polygons Model : Simplified by Mr. Ng Kok Why
 <kwng@mmu.edu.my>

 INSTRUCTIONS
 ============
 Please refer to CGLabmain.cpp for instructions

 SPECIAL NOTES
 =============
 * Try loading the high-polygons version of
 the Dragon model, it will be slow in slower PC.
 * Try out other models from http://graphics.stanford.edu/data/3Dscanrep/
 However, you will need to modify the file to comform to the
 format that is being used in this program.

 CHANGE LOG
 ==========
 */

#ifndef YP_CGLAB01_HPP
#define YP_CGLAB01_HPP

#include "CGLabmain.hpp"
#include "utilities/Mesh.hpp"
#include "utilities/Extrusion.hpp"
#include "utilities/Loft.hpp"
#include "utilities/VecMatMath.hpp"
#include <string>
#include <vector>

namespace CGLab01 {

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
    
    class MyModelLoader
    {
    public:
        MyModelLoader()
        {
        }
        ~MyModelLoader()
        {
        }
        //load a model and scale it
        void load(string filename, float scale = 1.0);
        void draw();
    private:
        vector<GLfloat> vertices;
        vector<int> faces;
        GLuint stanforddragon; //for generating display list
    };
    
    //------------------------------------
    //the main program will call methods from this class
    class MyVirtualWorld
    {
    public:
        SimplePolygon      simplepolygon;
        SimpleBox          simplebox;
        SimpleTriangles    simpletriangles;
        SimpleTeapot       simpleteapot;
        SimpleBouncingBall simplebouncingball;
        MyModelLoader      mymodelloader;
        Mesh *deer;
        Mesh *elephant;
        vector<vec2> points;
        Extrusion *extrude;
        
        Loft *loft;
        
        vector<vec3> pts, ptsTransformed,points3d;
        
        long int timeold, timenew, elapseTime;
        
        void draw();
        
        ~MyVirtualWorld() {
            delete deer;
            delete elephant;
            delete extrude;
        }
        
        void tickTime()
        {
            
            timenew    = glutGet(GLUT_ELAPSED_TIME);
            elapseTime = timenew - timeold;
            timeold    = timenew;
            
            simplebouncingball.tickTime(elapseTime);
        }
        
        //for any one-time only initialization of the
        //   virtual world before any rendering takes place
        //   BUT after OpenGL has been initialized
        void init()
        {
            glEnable(GL_LIGHTING);
            
/*
            points = {
                {{ -4.0f, -5.0f }}, {{ -4.0f,  5.0f }},
                {{  0.0f,  7.0f }}, {{  4.0f,  5.0f }},
                {{  4.0f, -5.0f }}, {{  0.0f, -7.0f }}
            };
            
*/
            points3d = {
                {{ -4.0f, -5.0f,5.0f }},
                {{  4.0f,  5.0f,5.0f }},
                {{  8.0f,  7.0f,5.0f }},
                {{  12.0f,  5.0f,5.0f }},
                {{  16.0f, -5.0f,5.0f }},
                {{  20.0f, -7.0f,5.0f }}
            };

            auto circle = getCircle(2, 10);
            for (auto &v : circle) points.push_back({{ v[0], v[2] }});

            //spring:
            points3d = generateSpline(-50, 50, 150,
                                      [](float z)->float { return sin(z/2.0) * 15; },
                                      [](float x)->float { return cos(x/2.0) * 15; },
                                      [](float y)->float { return y; });
            // heart:
            /*
            points3d = generateSpline(-50, 50, 150,
                                      [](float z)->float {
                                            float t = z/5.0;
                                            return 16 * sin(t) * sin(t) * sin(t);
                                        },
                                      [](float x)->float {
                                            float t = x/5.0;
                                            return 13 * cos(t) - 5*cos(2*t) - 2*cos(3*t) - cos(4*t);
                                        });
            */

            extrude = new Extrusion(points);
            extrude->setDepth(8);
            loft = new Loft(points, points3d);
            
            //Low-polygons dragon (5835 triangles)
            mymodelloader.load("data/model_lowpolygonstanforddragon.txt",100);
            deer = new Mesh("data/deer.obj");
            deer->setFlatColor({{.8, .2, .8}});
            deer->setTranslateX(10.5f);
            deer->setScale(0.5f);
            
            elephant = new Mesh("data/elephant-triangulated.obj");
            elephant->setFlatColor({{ .8, .1, .15 }});
            elephant->setTranslateX(-10.5f);
            elephant->setRotateY(-45.0f);
            
            pts = getCircle(8, 7);
            
            vec3 startNormal  = {{ 0, 1, 0 }};
            vec3 targetNormal = {{ 0.3333, 0.3333, 0.3333 }};
            mat3 rotationMatrix = getRotationMatrix(startNormal, targetNormal);
            
            for (auto &p : pts) {
                ptsTransformed.push_back(mult(rotationMatrix, p));
            }
            //Try this:
            //High-polygons dragon (original model of Stanford Dragon)
            // (871414 triangles) will take some minutes for it to get loaded
            //mymodelloader.load("data/model_highpolygonstanforddragon.txt",100);
            
            //mymodelloader.load("data/model_rose.txt", 0.2);
            
            //mymodelloader.load("data/model_shuttle.txt", 0.1);
            
            timeold = glutGet(GLUT_ELAPSED_TIME);
            
        }
    };
    
}; //end of namespace CGLab01

#endif //YP_CGLAB01_HPP
