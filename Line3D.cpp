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
    
    length = sqrt(pow(pt1.getX() - pt2.getX(), 2) + pow(pt1.getY() - pt2.getY(), 2) + pow(pt1.getZ() + pt2.getZ(), 2));
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
