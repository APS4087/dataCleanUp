#ifndef POINT2D_H
#define POINT2D_H

#include <cmath>

class Point2D {
protected:
    int x;
    int y;
    double distFrOrigin;
    void setDistFrOrigin();

public:
    Point2D(int x, int y);
    int getX() const;
    int getY() const;
    double getScalarValue() const;
    void setX(int x);
    void setY(int y);
    bool operator<(const Point2D& other) const;
    bool operator!=(const Point2D& other) const;
    bool operator==(const Point2D& other) const;
    
};

#endif // POINT2D_H
