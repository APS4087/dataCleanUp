#include "Point2D.h"

Point2D::Point2D(int x, int y): x(x), y(y) {
    setDistFrOrigin();
}

int Point2D::getX() const {
    return x;
}

int Point2D::getY() const{
    return y;
}

double Point2D::getScalarValue() {
    return distFrOrigin;
}

void Point2D::setX(int x) {
    this->x = x;
}

void Point2D::setY(int y) {
    this->y = y;
}

void Point2D::setDistFrOrigin() {
    distFrOrigin = sqrt(x * x + y * y);
}

bool Point2D::operator<(const Point2D& other) const {
    if (x != other.x) return x < other.x;
    return y < other.y;
}

bool Point2D::operator!=(const Point2D& other) const {
    return !(*this == other);
}

bool Point2D::operator==(const Point2D& other) const {
    return x == other.x && y == other.y;
}
