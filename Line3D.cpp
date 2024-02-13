#include "Line3D.h"

Line3D::Line3D(Point3D pt1, Point3D pt2) : Line2D(Point2D(pt1.getX(), pt1.getY()), Point2D(pt2.getX(), pt2.getY())), pt1(pt1), pt2(pt2) {
    setLength();
}

Point3D Line3D::getPt1() const{
    return pt1;
}

Point3D Line3D::getPt2() const{
    return pt2;
}

void Line3D::setPt1(Point3D pt1) {
    this->pt1 = pt1;
    setLength();
}

void Line3D::setPt2(Point3D pt2) {
    this->pt2 = pt2;
    setLength();
}

void Line3D::setLength() {
    double x1 = pt1.getX();
    double y1 = pt1.getY();
    double z1 = pt1.getZ();
    double x2 = pt2.getX();
    double y2 = pt2.getY();
    double z2 = pt2.getZ();
    length = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

// Less than operator
bool Line3D::operator<(const Line3D& other) const {
    if (pt1 != other.pt1) return pt1 < other.pt1;
    return pt2 < other.pt2;
}

bool Line3D::operator!=(const Line3D& other) const {
    return !(pt1 == other.pt1 && pt2 == other.pt2);
}

bool Line3D::operator==(const Line3D& other) const {
    return pt1 == other.pt1 && pt2 == other.pt2;
}
