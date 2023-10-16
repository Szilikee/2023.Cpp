//
// Created by Szilikee on 2023. 10. 16..
//

#ifndef POINTSET_H
#define POINTSET_H
#include "Point.h"
#include <vector>
using namespace std;


class PointSet{
    vector<Point> points;
    int n;
    vector<double> distances;
public:
    PointSet( int n = 100 );
    double maxDistance() const;
    double minDistance() const;
    int numDistances() const;
    void printPoints() const;
    void printDistances() const;
    void sortPointsX();
    void sortPointsY();
    void sortDistances();
    int numDistinctDistances();

    void computeDistances();
};
#endif /* POINTSET_H */