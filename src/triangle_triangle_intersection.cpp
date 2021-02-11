#include "triangle_triangle_intersection.h"
#include "ray_intersect_triangle.h"

bool triangle_triangle_intersection(
  const Eigen::RowVector3d & A0,
  const Eigen::RowVector3d & A1,
  const Eigen::RowVector3d & A2,
  const Eigen::RowVector3d & B0,
  const Eigen::RowVector3d & B1,
  const Eigen::RowVector3d & B2)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
	//A intersect B
	double t_temp;
	bool A_in_B = ray_intersect_triangle(Ray(A0, A2 - A0), B0, B1, B2, 0.0, 1.0, t_temp) ||
	ray_intersect_triangle(Ray(A1, A0 - A1), B0, B1, B2, 0.0, 1.0, t_temp) ||
	ray_intersect_triangle(Ray(A2, A1 - A2), B0, B1, B2, 0.0, 1.0, t_temp);
	//B intersect A
	bool B_in_A = ray_intersect_triangle(Ray(B0, B2 - B0), A0, A1, A2, 0.0, 1.0, t_temp) ||
		ray_intersect_triangle(Ray(B1, B0 - B1), A0, A1, A2, 0.0, 1.0, t_temp) ||
		ray_intersect_triangle(Ray(B2, B1 - B2), A0, A1, A2, 0.0, 1.0, t_temp);


  return A_in_B || B_in_A;
  ////////////////////////////////////////////////////////////////////////////
}
