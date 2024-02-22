#include "Line3D.h"

// Default constructor
Line3D::Line3D() : Line2D(), pt1(Point3D()), pt2(Point3D()) {
    setLength();
}

Line3D::Line3D(Point3D pt1, Point3D pt2) : Line2D(Point2D(pt1.getX(), pt1.getY()), Point2D(pt2.getX(), pt2.getY())), pt1(pt1), pt2(pt2) {
    setLength();
}

Point3D Line3D::getPt1() const{
    return this->pt1;
}

Point3D Line3D::getPt2() const{
    return this->pt2;
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

// Operator Overloading
bool Line3D::operator<(const Line3D &rhs) const { return ((this->pt1 < rhs.pt1) || (this->pt2 < rhs.pt2)); }
bool Line3D::operator==(const Line3D &rhs) const { return ((this->pt1 == rhs.pt1) && (this->pt2 == rhs.pt2)); }

// Friend Function
std::ostream &operator<<(std::ostream &out, const Line3D &line3D)
{
    out << Format::format3DCoordinates(line3D.getPt1().getX(), line3D.getPt1().getY(), line3D.getPt1().getZ());
    out << Format::addSpacing(3);
    out << Format::format3DCoordinates(line3D.getPt2().getX(), line3D.getPt2().getY(), line3D.getPt2().getZ());
    out << Format::addSpacing(3);
    out << Format::formatDistance(line3D.getScalarValue());
    return out;
}
