#include "point_box_squared_distance.h"
#include <math.h> 

double point_box_squared_distance(
	const Eigen::RowVector3d& query,
	const BoundingBox& box)
{
	////////////////////////////////////////////////////////////////////////////
	// Replace with your code here
	double x = std::max( std::max(box.min_corner(0) - query(0), query(0) - box.max_corner(0)), 0.0 );
	double y = std::max( std::max(box.min_corner(1) - query(1), query(1) - box.max_corner(1)), 0.0 );
	double z = std::max( std::max(box.min_corner(2) - query(2), query(2) - box.max_corner(2)), 0.0 );

	return pow(x, 2) + pow(y, 2) + pow(z, 2);
	////////////////////////////////////////////////////////////////////////////
}