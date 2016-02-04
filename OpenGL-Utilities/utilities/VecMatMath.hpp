#pragma once

#include <math.h>
#include <cmath>
#include <algorithm>
#include <functional>
#include <array>
#include <vector>
#include <float.h>

#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif

typedef std::array<float, 3> vec3;
typedef std::array<float, 2> vec2;
typedef std::array<vec3, 3> mat3;

vec3 cross(const vec3 &a, const vec3 &b);
vec3 mult(const mat3& m, const vec3& a);
mat3 getRotationMatrix(vec3 axis, float rads);
mat3 getRotationMatrix(const vec3 &sourceNormal, const vec3 &targetNormal);
// find the directional vector of each vertex given a polyspline
std::vector<vec3> getDirections(const std::vector<vec3> &spline);

std::vector<vec3> generateSpline(float start, float finish, int segments,
                                 std::function<float(float)> zFunc = [](float z)->float { return 0; },
                                 std::function<float(float)> xFunc = [](float x)->float { return x; },
                                 std::function<float(float)> yFunc = [](float y)->float { return 0; });

std::vector<vec3> getCircle(float radius, int segments, float y = 0, float start = 0, float finish = 6.2831853);

template<typename T>
float dot(const T &a, const T &b)
{
    float res = 0;

    for (int i = 0; i < a.size(); i++) {
        res += (a[i] * b[i]);
    }

    return res;
}

template<typename T>
float magnitude(const T &a)
{
    float sumSquare = 0;

    for (auto &b : a) {
        sumSquare += (b*b);
    }

    return std::sqrt(sumSquare);
}

template<typename T, typename R = typename T::value_type>
T applyVecOp(const T &a, const T &b, std::function<R(const R &p, const R &q)> op)
{
    T c;
    for (int i = 0; i < c.size(); i++) {
        c[i] = op(a[i], b[i]);
    }

    return c;
}

template<typename T, typename R = typename T::value_type>
T add(const T &a, const T &b)
{
    return applyVecOp<T, R>(a, b, [](const R &p, const R &q)->R { return p + q; });
}

template<typename T, typename R = typename T::value_type>
T deduct(const T &a, const T &b)
{
    return applyVecOp<T, R>(a, b, [](const R &p, const R &q)->R { return p - q; });
}

template<typename T, typename R = typename T::value_type>
T mult(const T &a, const T &b)
{
    return applyVecOp<T, R>(a, b, [](const R &p, const R &q)->R { return p * q; });
}

template<typename T>
T unitVec(const T &a)
{
    T unitV;
    float mag = magnitude(a);

    for (int i = 0; i < unitV.size(); i++) {
        unitV[i] = a[i] / mag;
    }

    return unitV;
}

template<typename T>
T negative(const T &a)
{
    T neg;

    for (int i = 0; i < neg.size(); i++) {
        neg[i] = -a[i];
    }

    return neg;
}

template<typename T>
T scalaMult(const T &a, int scalar) {
    for(int i = 0 ; i < a.size(); i++) {
        a *= scalar;
    }
    return a;
}

template<typename T, typename R = typename T::value_type>
T findCenter(const std::vector<T> &pts)
{
    if (pts.size() == 0) return T();

    T minVec, maxVec;
    for (auto &f : minVec) f = FLT_MAX;
    for (auto &f : maxVec) f = FLT_MIN;

    for (auto &p : pts) {
        for (int i = 0; i < minVec.size(); i++) {
            minVec[i] = std::min(minVec[i], p[i]);
            maxVec[i] = std::max(maxVec[i], p[i]);
        }
    }

    return applyVecOp<T, R>(minVec, maxVec, [](const R &p, const R &q)->R { return (p + q) / 2; });
}
template<typename T>
long long getDistance(std::vector<T> points) {
    long long sum_distance;
    for(int i = 1 ; i < points.size() ; i++) {
        for (int j = 0; j < points[i].size(); j++) {
             sum_distance += points[ i ][j] - points[i - 1][j];
        }
    }
    return sqrt(sum_distance);
}

std::vector<vec3> Bezier( vec3 point0,vec3 point1,vec3 point2,vec3 point3) {
    std::vector<vec3> points;
    
    if (getDistance(std::vector<vec3>{point0,point1,point2,point3})) {
        points = {point0,point1,point2,point3};
        return points;
    }
    vec3 point01 = scalaMult(add(point0, point1), 0.5);
    vec3 point12 = scalaMult(add(point1, point2), 0.5);
    vec3 point23 = scalaMult(add(point2, point3), 0.5);
    vec3 pointA =scalaMult(add(point01, point12), 0.5);
    vec3 pointB =scalaMult(add(point12, point23), 0.5);
    vec3 pointAB =scalaMult(add(pointA, pointB), 0.5);
    std::vector<vec3> tempvec = Bezier(point0,point01, pointA, pointAB);
    std::vector<vec3> tempvec2 = Bezier(pointAB, pointB, point23, point3);
    
    points.reserve( tempvec.size() + tempvec2.size() ); // preallocate memory
    points.insert( points.end(), tempvec.begin(), tempvec.end() ); // combine points and tempvec
    points.insert( points.end(), tempvec2.begin(), tempvec2.end() ); //ditto
    
    return points;
    
}
