#ifndef POINT3D_H
#define POINT3D_H

#include "Point2D.h"

class Point3D : public Point2D {
protected:
    int z;
    void setDistFrOrigin();

public:
    Point3D(int x, int y, int z);
    int getZ() const;
    void setZ(int z);
    bool operator<(const Point3D& other) const;
    bool operator!=(const Point3D& other) const;
    bool operator==(const Point3D& other) const;
};

#endif // POINT3D_H
