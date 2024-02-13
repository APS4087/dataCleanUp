#ifndef LINE3D_H
#define LINE3D_H

#include "Line2D.h"
#include "Point3D.h"

class Line3D : public Line2D {
private:
    Point3D pt1;
    Point3D pt2;

protected:
    void setLength();

public:
    Line3D(Point3D pt1, Point3D pt2);
    Point3D getPt1() const;
    Point3D getPt2() const;
    void setPt1(Point3D pt1);
    void setPt2(Point3D pt2);
    bool operator<(const Line3D& other) const;
    bool operator!=(const Line3D& other) const;
    bool operator==(const Line3D& other) const;
};

#endif // LINE3D_H
