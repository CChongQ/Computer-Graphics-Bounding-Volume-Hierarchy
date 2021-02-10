#include "ray_intersect_triangle_mesh_brute_force.h"
#include "ray_intersect_triangle.h"

bool ray_intersect_triangle_mesh_brute_force(
  const Ray & ray,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const double min_t,
  const double max_t,
  double & hit_t,
  int & hit_f)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  bool return_hit_f = false;
  double t_temp = 0;
  double t_closest = std::numeric_limits<double>::infinity();
  double hit_closest = -1;

  for (int i = 0; i < F.rows(); i++ ){
    const Eigen::RowVector3d A = V.row(F(i,0));
    const Eigen::RowVector3d B = V.row(F(i,1));
    const Eigen::RowVector3d C = V.row(F(i,2));
    bool found_hit = ray_intersect_triangle(ray, A,B,C,min_t,max_t,t_temp);
    if (found_hit){
      if (t_temp < t_closest ){
        t_closest = t_temp;
        hit_closest = i;
      }
      return_hit_f = true;
    }
  }
  hit_t = t_closest;
  hit_f = hit_closest;

  return return_hit_f;
  ////////////////////////////////////////////////////////////////////////////
}
