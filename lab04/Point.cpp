//
// Created by Szilikee on 2023. 10. 16..
//

#include <cmath>
#include "Point.h"
#include <iostream>
using namespace std;


Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

double Point::distanceTo(const Point &point) const {
    return sqrt(pow(this->x - point.x, 2) + pow(this->y - point.y, 2));
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::print() const{
    cout << ")"<< x << "," << y << ")" << endl;
}
