#include "Point3D.h"

Point3D::Point3D(int x, int y, int z) : Point2D(x, y) , z(z){
    setDistFrOrigin();
}

int Point3D::getZ() const{
    return z;
}

void Point3D::setZ(int z) {
    this->z = z;
    setDistFrOrigin();
}

void Point3D::setDistFrOrigin() {
    distFrOrigin = sqrt(x * x + y * y + z * z);
}

bool Point3D::operator<(const Point3D& other) const {
    if (x != other.x) return x < other.x;
    if (y != other.y) return y < other.y;
    return z < other.z;
}

bool Point3D::operator!=(const Point3D& other) const {
    return !(*this == other);
}

bool Point3D::operator==(const Point3D& other) const {
    return x == other.x && y == other.y && z == other.z;
}
