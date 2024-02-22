#include "sortHelper.h"

// Comparator Function
// X            // Point 2D, 3D, Line 2D
bool sortHelper::sortXByAscending(const Point2D& lhs, const Point2D& rhs) { return lhs.getX() < rhs.getX(); }
bool sortHelper::sortXByDescending(const Point2D& lhs, const Point2D& rhs) { return lhs.getX() > rhs.getX(); }

// Y            // Point 2D, 3D, Line 2D
bool sortHelper::sortYByAscending(const Point2D& lhs, const Point2D& rhs) { return lhs.getY() < rhs.getY(); }
bool sortHelper::sortYByDescending(const Point2D& lhs, const Point2D& rhs) { return lhs.getY() > rhs.getY(); }

// Z            // Point 3D
bool sortHelper::sortZByAscending(const Point3D& lhs, const Point3D& rhs) { return lhs.getZ() < rhs.getZ(); }
bool sortHelper::sortZByDescending(const Point3D& lhs, const Point3D& rhs) { return lhs.getZ() > rhs.getZ(); }

// Distance     // Point 2D, 3D
bool sortHelper::sortPtByDistanceAscending(const Point2D& lhs, const Point2D& rhs) { return lhs.getScalarValue() < rhs.getScalarValue(); }
bool sortHelper::sortPtByDistanceDescending(const Point2D& lhs, const Point2D& rhs) { return lhs.getScalarValue() > rhs.getScalarValue(); }

// PT 1's XY    // Line 2D
bool sortHelper::sortLine2DByXYPt1Ascending(const Line2D& lhs, const Line2D& rhs) { return ((lhs.getPt1().getX() == rhs.getPt1().getX()) ? sortYByAscending(lhs.getPt1(), rhs.getPt1()) : sortXByAscending(lhs.getPt1(), rhs.getPt1())); }
bool sortHelper::sortLine2DByXYPt1Descending(const Line2D& lhs, const Line2D& rhs) { return ((lhs.getPt1().getX() == rhs.getPt1().getX()) ? sortYByDescending(lhs.getPt1(), rhs.getPt1()) : sortXByDescending(lhs.getPt1(), rhs.getPt1())); }

// PT 2's XY    // Line 2D
bool sortHelper::sortLine2DByXYPt2Ascending(const Line2D& lhs, const Line2D& rhs) { return ((lhs.getPt2().getX() == rhs.getPt2().getX()) ? sortYByAscending(lhs.getPt2(), rhs.getPt2()) : sortXByAscending(lhs.getPt2(), rhs.getPt2())); }
bool sortHelper::sortLine2DByXYPt2Descending(const Line2D& lhs, const Line2D& rhs) { return ((lhs.getPt2().getX() == rhs.getPt2().getX()) ? sortYByDescending(lhs.getPt2(), rhs.getPt2()) : sortXByDescending(lhs.getPt2(), rhs.getPt2())); }

// Distance     // Line 2D, 3D
bool sortHelper::sortLineByDistanceAscending(const Line2D& lhs, const Line2D& rhs) { return lhs.getScalarValue() < rhs.getScalarValue(); }
bool sortHelper::sortLineByDistanceDescending(const Line2D& lhs, const Line2D& rhs) { return lhs.getScalarValue() > rhs.getScalarValue(); }

// PT 1's XY    // Line 3D
bool sortHelper::sortLine3DByXYPt1ascending(const Line3D& lhs, const Line3D& rhs) { return ((lhs.getPt1().getX() == rhs.getPt1().getX()) ? sortYByAscending(lhs.getPt1(), rhs.getPt1()) : sortXByAscending(lhs.getPt1(), rhs.getPt1())); }
bool sortHelper::sortLine3DByXYPt1Descending(const Line3D& lhs, const Line3D& rhs) { return ((lhs.getPt1().getX() == rhs.getPt1().getX()) ? sortYByDescending(lhs.getPt1(), rhs.getPt1()) : sortXByDescending(lhs.getPt1(), rhs.getPt1())); }

// PT 2's XY    // Line 3D
bool sortHelper::sortLine3DByXYPt2ascending(const Line3D& lhs, const Line3D& rhs) { return ((lhs.getPt2().getX() == rhs.getPt2().getX()) ? sortYByAscending(lhs.getPt2(), rhs.getPt2()) : sortXByAscending(lhs.getPt2(), rhs.getPt2())); }
bool sortHelper::sortLine3DByXYPt2Descending(const Line3D& lhs, const Line3D& rhs) { return ((lhs.getPt2().getX() == rhs.getPt2().getX()) ? sortYByDescending(lhs.getPt2(), rhs.getPt2()) : sortXByDescending(lhs.getPt2(), rhs.getPt2())); }
