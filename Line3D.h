#ifndef LINE3D_H
#define LINE3D_H

#include "Line2D.h"
#include "Point3D.h"
#include "Format.h"

class Line3D : public Line2D {
    friend std::ostream &operator<<(std::ostream &out, const Line3D &line3D); // out << line3D
private:
    Point3D pt1;
    Point3D pt2;

protected:
    void setLength();


public:
    Line3D();
    Line3D(Point3D pt1, Point3D pt2);
    Point3D getPt1() const;
    Point3D getPt2() const;
    void setPt1(Point3D pt1);
    void setPt2(Point3D pt2);
    // Operator Overloading
    bool operator<(const Line3D &rhs) const;
    bool operator==(const Line3D &rhs) const;
};

#endif // LINE3D_H
