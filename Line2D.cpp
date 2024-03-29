#include "Line2D.h"
#include <cmath>

// Default constructor
Line2D::Line2D() : pt1(Point2D()), pt2(Point2D()), length(0) {}

Line2D::Line2D(Point2D pt1, Point2D pt2) : pt1(pt1), pt2(pt2) {
    setLength();
}

Point2D Line2D::getPt1() const{
    return this->pt1;
}

Point2D Line2D::getPt2() const{
    return this->pt2;
}

double Line2D::getScalarValue() const {
    return this->length;
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
    length = sqrt(pow(pt1.getX() - pt2.getX(), 2) + pow(pt1.getY() - pt2.getY(), 2));
}




// Operator Overloading
bool Line2D::operator<(const Line2D &rhs) const { return ((this->pt1 < rhs.pt1) || (this->pt2 < rhs.pt2)); }
bool Line2D::operator==(const Line2D &rhs) const { return ((this->pt1 == rhs.pt1) && (this->pt2 == rhs.pt2)); }

// Friend Function
std::ostream &operator<<(std::ostream &out, const Line2D &line2D)
{
    out << Format::format2DCoordinates(line2D.getPt1().getX(), line2D.getPt1().getY());
    out << Format::addSpacing(3);
    out << Format::format2DCoordinates(line2D.getPt2().getX(), line2D.getPt2().getY());
    out << Format::addSpacing(3);
    out << Format::formatDistance(line2D.getScalarValue());
    return out;
}