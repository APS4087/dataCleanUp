#include "Line2D.h"
#include <cmath>

Line2D::Line2D(Point2D pt1, Point2D pt2) : pt1(pt1), pt2(pt2) {
    setLength();
}

Point2D Line2D::getPt1() const{
    return pt1;
}

Point2D Line2D::getPt2() const{
    return pt2;
}

double Line2D::getScalarValue() {
    return length;
}

void Line2D::setPt1(Point2D pt1) {
    this->pt1 = pt1;
    setLength();
}

void Line2D::setPt2(Point2D pt2) {
    this->pt2 = pt2;
    setLength();
}

void Line2D::setLength() {
    int x1 = pt1.getX();
    int y1 = pt1.getY();
    int x2 = pt2.getX();
    int y2 = pt2.getY();
    length = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Less than operator
bool Line2D::operator < (const Line2D& other) const {
    if (pt1 != other.pt1) return pt1 < other.pt1;
    return pt2 < other.pt2;
}


bool Line2D::operator!=(const Line2D& other) const {
    return !(pt1 == other.pt1 && pt2 == other.pt2);
}

bool Line2D::operator==(const Line2D& other) const {
    return pt1 == other.pt1 && pt2 == other.pt2;
}