//
// Created by Szilikee on 10/2/2023.
//

#include "Point.h"
#include "util.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <utility>
#include <algorithm>

using namespace std;


double util::distance(const Point &a, const Point &b) {
    return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
}

bool util::isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    return util::distance(a, b) == util::distance(c, d);
}


void util::testIsSquare(const char *filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Fajl nem talalhato!" << endl;
    }
    string line;
    string text;
    while (getline(file, line)) {
        istringstream iss(line);
        vector<Point> points;
        int x, y;
        while (iss >> x >> y) {
            Point point;
            point.x = x;
            point.y = y;
            points.push_back(point);
        }

        if (points.size() == 4) {
            bool result = util::isSquare(points[0], points[1], points[2], points[3]);
            cout << "Pontok: ";
            for (const auto &point: points) {
                cout << "(" << point.getX() << ", " << point.getY() << ") ";
            }
            cout << (result ? "YES" : "NO") << endl;
        } else {
            cout << "Hiba: " << line << "" << endl;
        }
    }
    file.close();
}

Point *util::randomArray(int size) {
    Point *pontok = new Point[size];
    for (int i = 0; i < size; ++i) {
        pontok[i].x = rand() % 2000;
        pontok[i].y = rand() % 2000;
    }
    return pontok;
}

void util::printArray(Point *points, int numPoints) {
    for (int i = 0; i < numPoints; ++i) {
        cout << "(" << points[i].getX() << ", " << points[i].getY() << ") ";
    }
}

std::pair<Point, Point> util::closestPoints(Point *points, int numPoints) {
    if (numPoints < 2) {
        return std::make_pair(Point{0, 0}, Point{0, 0});
    }
    Point closest1 = points[0];
    Point closest2 = points[1];
    double minDistance = util::distance(closest1, closest2);

    for (int i = 0; i < numPoints - 1; i++) {
        for (int j = i + 1; j < numPoints; j++) {
            double d = util::distance(points[i], points[j]);
            if (d < minDistance) {
                minDistance = d;
                closest1 = points[i];
                closest2 = points[j];
            }
        }
    }

    return std::make_pair(closest1, closest2);
}

std::pair<Point, Point> util::farthestPoints(Point *points, int numPoints) {
    if (numPoints < 2) {
        return std::make_pair(Point{0, 0}, Point{0, 0});
    }
    Point tavolabbi1 = points[0];
    Point tavolabbi2 = points[1];
    double minDistance = util::distance(tavolabbi1, tavolabbi2);

    for (int i = 0; i < numPoints - 1; i++) {
        for (int j = i + 1; j < numPoints; j++) {
            double d = util::distance(points[i], points[j]);
            if (d > minDistance) {
                minDistance = d;
                tavolabbi1 = points[i];
                tavolabbi2 = points[j];
            }
        }
    }

    return std::make_pair(tavolabbi1, tavolabbi2);
}

bool comparePoints(const Point &a, const Point &b) {
    return a.x < b.x;
}

void util::sortPoints(Point *points, int numPoints) {
    std::sort(points, points + numPoints, comparePoints);
    for (int i = 0; i < numPoints; i++) {
        std::cout << "Pont " << i + 1 << ": (" << points[i].x << ", " << points[i].y << ")" << std::endl;
    }
}

double util::distanceFromOrigin(const Point &p) {
    return std::sqrt(p.x * p.x + p.y * p.y);
}

Point util::farthestPointFromOrigin(Point *points, int numPoints) {

    Point farthest = points[0];
    double maxDistance = distanceFromOrigin(farthest);

    for (int i = 1; i < numPoints; i++) {
        double currentDistance = distanceFromOrigin(points[i]);
        if (currentDistance > maxDistance) {
            maxDistance = currentDistance;
            farthest = points[i];
        }
    }

    return farthest;
}

void util::deletePoints(Point *points) {
    delete[] points;
}
