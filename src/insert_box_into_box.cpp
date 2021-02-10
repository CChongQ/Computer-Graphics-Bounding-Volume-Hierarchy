#include "insert_box_into_box.h"

void insert_box_into_box(
  const BoundingBox & A,
  BoundingBox & B)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  BoundingBox B_temp;

  B_temp.min_corner[0] = std::min( A.min_corner[0] , B.min_corner[0] );
  B_temp.min_corner[1] = std::min( A.min_corner[1] , B.min_corner[1] );
  B_temp.min_corner[2] = std::min( A.min_corner[2] , B.min_corner[2] );

  B_temp.max_corner[0] = std::max( A.max_corner[0], B.max_corner[0] );
  B_temp.max_corner[1] = std::max( A.max_corner[1], B.max_corner[1] );
  B_temp.max_corner[2] = std::max( A.max_corner[2], B.max_corner[2] );

  B = B_temp;

  ////////////////////////////////////////////////////////////////////////////
}

