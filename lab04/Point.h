//
// Created by Szilikee on 2023. 10. 16..
//

#ifndef POINT_H
#define POINT_H
#define M 2000

class Point{
private:
    int x, y;
public:
    Point( int x=0, int y=0);
    int getX() const;
    int getY() const;
    double distanceTo(const Point& point)const;
    void print() const;
};


#endif /* PONT_H */
