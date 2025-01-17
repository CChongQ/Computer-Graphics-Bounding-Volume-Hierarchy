#include "box_box_intersect.h"
bool box_box_intersect(
    const BoundingBox& A,
    const BoundingBox& B)
{
    ////////////////////////////////////////////////////////////////////////////
    // Replace with your code here:
    bool x_in = A.min_corner[0] < B.max_corner[0] && A.max_corner[0] > B.min_corner[0];
    bool y_in = A.min_corner[1] < B.max_corner[1] && A.max_corner[1] > B.min_corner[1];
    bool z_in = A.min_corner[2] < B.max_corner[2] && A.max_corner[2] > B.min_corner[2];

    return x_in && y_in && z_in;

    ////////////////////////////////////////////////////////////////////////////
}