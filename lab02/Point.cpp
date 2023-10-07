//
// Created by Szilikee on 10/2/2023.
//

#include <iostream>
#include <cmath>
#include "Point.h"

using namespace std;
Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000){
        this->x = x;
        this->y = y;
    }
    else{
        this->x = 0;
        this->y = 0;
    }
}
int Point::getX() const {
    return x;
}
int Point::getY() const {
    return y;
}
void Point:: print() const{
    cout<<"("<<x<<","<<y<<")"<<endl;
}

double Point::distance(const Point& a, const Point& b){
    return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
}

