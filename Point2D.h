#ifndef POINT2D_H
#define POINT2D_H

#include <cmath>
#include <iostream>
#include <ostream>
#include "Format.h"

class Point2D {
    friend std::ostream &operator<<(std::ostream &out, const Point2D &point2D); // out << point2D
protected:
    int x;
    int y;
    double distFrOrigin;
    void setDistFrOrigin();

public:
    Point2D();
    Point2D(int x, int y);
    int getX() const;
    int getY() const;
    double getScalarValue() const;
    void setX(int x);
    void setY(int y);
    // Operator Overloading
    bool operator<(const Point2D &rhs) const;
    bool operator==(const Point2D &rhs) const;
    
};

#endif // POINT2D_H
