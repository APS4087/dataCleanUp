#ifndef SORTHELPER_H
#define SORTHELPER_H

#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"

namespace sortHelper
{
// Comparator Function
// X            // Point 2D, 3D, Line 2D
bool sortXByAscending(const Point2D &lhs, const Point2D &rhs);
bool sortXByDescending(const Point2D &lhs, const Point2D &rhs);

// Y            // Point 2D, 3D, Line 2D
bool sortYByAscending(const Point2D &lhs, const Point2D &rhs);
bool sortYByDescending(const Point2D &lhs, const Point2D &rhs);

// Z            // Point 3D
bool sortZByAscending(const Point3D &lhs, const Point3D &rhs);
bool sortZByDescending(const Point3D &lhs, const Point3D &rhs);

// Distance     // Point 2D, 3D
bool sortPtByDistanceAscending(const Point2D &lhs, const Point2D &rhs);
bool sortPtByDistanceDescending(const Point2D &lhs, const Point2D &rhs);

// PT 1's XY    // Line 2D
bool sortLine2DByXYPt1Ascending(const Line2D &lhs, const Line2D &rhs);
bool sortLine2DByXYPt1Descending(const Line2D &lhs, const Line2D &rhs);

// PT 2's XY    // Line 2D
bool sortLine2DByXYPt2Ascending(const Line2D &lhs, const Line2D &rhs);
bool sortLine2DByXYPt2Descending(const Line2D &lhs, const Line2D &rhs);

// Distance     // Line 2D, 3D
bool sortLineByDistanceAscending(const Line2D &lhs, const Line2D &rhs);
bool sortLineByDistanceDescending(const Line2D &lhs, const Line2D &rhs);

// PT 1's XY    // Line 3D
bool sortLine3DByXYPt1ascending(const Line3D &lhs, const Line3D &rhs);
bool sortLine3DByXYPt1Descending(const Line3D &lhs, const Line3D &rhs);

// PT 2's XY    // Line 3D
bool sortLine3DByXYPt2ascending(const Line3D &lhs, const Line3D &rhs);
bool sortLine3DByXYPt2Descending(const Line3D &lhs, const Line3D &rhs);
}
#endif