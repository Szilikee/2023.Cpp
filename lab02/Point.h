//
// Created by Szilikee on 10/2/2023.
//

#ifndef MAIN_02_CPP_POINT_H
#define MAIN_02_CPP_POINT_H


class Point {
    public:
        int x, y;
    public:
        Point( int x=0, int y=0);
        int getX() const;
        int getY() const;
        void print() const;
        double distance(const Point& a, const Point& b);


};


#endif //MAIN_02_CPP_POINT_H
