#include "ray_intersect_box.h"
#include <iostream>

bool ray_intersect_box(
  const Ray & ray,
  const BoundingBox& box,
  const double min_t,
  const double max_t)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  //pseudocode: textbook 12.3.1
  double x_min = box.min_corner[0];
  double x_max = box.max_corner[0];
  double y_min = box.min_corner[1];
  double y_max = box.max_corner[1];
  double z_min = box.min_corner[2];
  double z_max = box.max_corner[2];

  double t_xmin, t_xmax,t_ymin, t_ymax,t_zmin, t_zmax;

  double x_d = ray.direction[0];
  double y_d = ray.direction[1];
  double z_d = ray.direction[2];

  double x_e = ray.origin[0];
  double y_e = ray.origin[1];
  double z_e = ray.origin[2];

  if ( x_d >= 0) {
    t_xmin = (x_min-x_e)/x_d;
    t_xmax = (x_max-x_e)/x_d;
  }
  else{
    t_xmin = (x_max-x_e)/x_d;
    t_xmax = (x_min-x_e)/x_d;
  }

  if ( y_d >= 0) {
    t_ymin = (y_min-y_e)/y_d;
    t_ymax = (y_max-y_e)/y_d;
  }
  else{
    t_ymin = (y_max-y_e)/y_d;
    t_ymax = (y_min-y_e)/y_d;
  }

  if ( z_d >= 0) {
    t_zmin = (z_min-z_e)/z_d;
    t_zmax = (z_max-z_e)/z_d;
  }
  else{
    t_zmin = (z_max-z_e)/z_d;
    t_zmax = (z_min-z_e)/z_d;
  }

  double min_temp = std::max( std::max(t_xmin,t_ymin) ,t_zmin);
  double max_temp = std::min( std::min(t_xmax,t_ymax) ,t_zmax);
  if (max_temp < min_temp)
    return false;
  if (max_temp > max_t && min_temp < min_t)
    return false;

  return true;

  ////////////////////////////////////////////////////////////////////////////
}
