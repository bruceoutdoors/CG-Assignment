#include <iostream>
#include <cassert>
#include "utilities/VecMatMath.hpp"

using namespace std;
//
//int main()
//{
//    vec2 found2, expected2;
//    std::vector<vec2> points = { {{ 0, 2 }}, {{ 2, 0 }} };
//    found2 = findCenter(points);
//    expected2 = {{ 1, 1 }};
//
//    assert(found2 == expected2);
//
//    vec3 found3, expected3;
//
//    vec3 p, q;
//    p = {{ 1, 2, -5 }}; q = {{ 9, -3, 1 }};
//    found3 = add(p, q);
//    expected3 = {{ 10, -1, -4 }};
//
//    assert(found3 == expected3);
//
//    found3 = cross({{ 1, 2, -5 }}, {{ 9, -3, 1 }});
//    expected3 = {{ -13, -46, -21 }};
//
//    assert(found3 == expected3);
//
//    found3 = unitVec(expected3);
//    int mag = magnitude(found3);
//
//    assert(mag == 1);
//
//    vec3 a = {{ 2, 1, 3 }};
//    mat3 m = {{
//         {{ 1, 4, 7 }},
//         {{ 2, 5, 8 }},
//         {{ 3, 6, 9 }}
//    }};
//    found3 = mult(m, a);
//    expected3 = {{ 13, 31, 49 }};
//
//    assert(found3 == expected3);
//
//    std::vector<vec3> spline = {
//        {{ 0, 0, 0 }},
//        {{ 0, 3, 0 }},
//        {{ 0, 3, 3 }}
//    };
//
//    std::vector<vec3> directions = getDirections(spline);
////    for (auto &l : directions) {
////        for (auto &h : l) cout << h << "   ";
////        cout << endl;
////    }
//
//    vec3 exp1 = {{ 0, 1, 0 }};
//    vec3 exp2 = {{ 0, 0, 1 }};
//    assert(directions[0] == exp1);
//    assert(directions[2] == exp2);
//    assert(directions[1][1] == directions[1][2]);
//
//    // if only 1 vertex, no direction:
//    spline.clear();
//    spline.push_back({{ 0, 5, 0 }});
//    directions = getDirections(spline);
//    assert(directions.size() == 0);
//
//    // if spline is just a line, the direction of both vertices are the same
//    spline.clear();
//    spline.push_back({{ 0, 5, 0 }});
//    spline.push_back({{ 0, 8, 0 }});
//    directions = getDirections(spline);
//    assert(directions.size() == 2);
//    assert(directions[1] == directions[0]);
//
//    return 0;
//}
