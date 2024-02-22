#ifndef LINE2D_H
#define LINE2D_H

#include "Point2D.h"
#include "format.h"

class Line2D {
    friend std::ostream &operator<<(std::ostream &out, const Line2D &line2D); // out << line2D
private:
    Point2D pt1;
    Point2D pt2;


protected:
    double length;
    void setLength();

public:
    Line2D();
    Line2D(Point2D pt1, Point2D pt2);
    Point2D getPt1() const;
    Point2D getPt2() const;
    double getScalarValue() const;
    void setPt1(Point2D pt1);
    void setPt2(Point2D pt2);
    // Operator Overloading
    bool operator<(const Line2D &rhs) const;
    bool operator==(const Line2D &rhs) const;
};

#endif // LINE2D_H

