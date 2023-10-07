//
// Created by Otto on 10/2/2023.
//

#ifndef MAIN_02_CPP_UTIL_H
#define MAIN_02_CPP_UTIL_H
#include <utility>

class util {

public:
    static bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
    static double distance(const Point& a, const Point& b);
    void testIsSquare(const char *filename);
    Point* randomArray(int size);
    void printArray(Point* points, int numPoints);
    static std::pair<Point, Point> closestPoints(Point* points, int numPoints);
    static std::pair<Point, Point> farthestPoints(Point* points, int numPoints);
    void sortPoints(Point* points, int numPoints);
    double distanceFromOrigin(const Point& p);
    Point farthestPointFromOrigin(Point* points, int numPoints);
    void deletePoints(Point* points);
};


#endif //MAIN_02_CPP_UTIL_H
