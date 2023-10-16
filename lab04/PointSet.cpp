//
// Created by Szilikee on 2023. 10. 16..
//

#include "PointSet.h"
#include <random>
#include <iostream>
#include <algorithm>
using namespace std;

PointSet::PointSet(int n) {
    random_device rd;
    mt19937 st(rd());
    uniform_int_distribution<int> dist(0, 1000);

    for (int i = 0; i < n; ++i) {
        int x = dist(st);
        int y = dist(st);
        Point newPoint(x, y);
        points.push_back(newPoint);
    }
}


void PointSet::computeDistances() {
    for (int i = 0; i < points.size(); ++i) {
        for (int j = i + 1; j < points.size(); ++j) {
            double distance;
            distance = points[i].distanceTo(points[j]);
            distances.push_back(distance);
        }
    }
}

double PointSet::maxDistance() const {
    double max = distances[0];
    for (int i = 1; i < distances.size(); ++i) {
        if (distances[i] > max) {
            max = distances[i];
        }
    }
    return max;
}

double PointSet::minDistance() const {
    double min = distances[0];
    for (int i = 1; i < distances.size(); ++i) {
        if (distances[i] < min) {
            min = distances[i];
        }
    }
    return min;
}

int PointSet::numDistances() const {
    return distances.size();
}

void PointSet::printPoints() const {
    for (int i = 0; i < points.size(); ++i) {
        points[i].print();
    }
}

void PointSet::printDistances() const {
    for (int i = 0; i < distances.size(); ++i) {
        cout << distances[i] << endl;
    }
}

void PointSet::sortPointsX() {
    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.getX() < b.getX();
    });
}

void PointSet::sortPointsY() {
    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.getY() < b.getY();
    });
}

void PointSet::sortDistances() {
    sort(distances.begin(), distances.end());
}

int PointSet::numDistinctDistances() {
    vector<double> newVector = distances;
    auto last = unique(newVector.begin(), newVector.end());
    return last - newVector.begin();
}

