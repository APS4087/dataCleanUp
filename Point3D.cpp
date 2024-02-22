#include "Point3D.h"

// Default constructor
Point3D::Point3D() : Point2D(), z(0) {
    setDistFrOrigin();
}

Point3D::Point3D(int x, int y, int z) : Point2D(x, y) , z(z){
    setDistFrOrigin();
}

int Point3D::getZ() const{
    return this->z;
}

void Point3D::setZ(int z) {
    this->z = z;
    setDistFrOrigin();
}

void Point3D::setDistFrOrigin() {
    distFrOrigin = sqrt(x * x + y * y + z * z);
}

// Operator Overloading
bool Point3D::operator<(const Point3D &rhs) const { return (Point2D::operator<(rhs) || this->z < rhs.z); }
bool Point3D::operator==(const Point3D &rhs) const { return (Point2D::operator==(rhs) && this->z == rhs.z); }

// Friend Function
std::ostream &operator<<(std::ostream &out, const Point3D &point3D)
{
    out << Format::format3DCoordinates(point3D.getX(), point3D.getY(), point3D.getZ());
    out << Format::addSpacing(3);
    out << Format::formatDistance(point3D.getScalarValue());
    return out;
}
