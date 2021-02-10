#include "ray_intersect_triangle.h"
#include <Eigen/Dense>
using namespace Eigen;

bool ray_intersect_triangle(
  const Ray & ray,
  const Eigen::RowVector3d & A,
  const Eigen::RowVector3d & B,
  const Eigen::RowVector3d & C,
  const double min_t,
  const double max_t,
  double & t)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  const Eigen::RowVector3d & a = A.transpose(); 
  const Eigen::RowVector3d & b = B.transpose(); 
  const Eigen::RowVector3d & c = C.transpose(); 
  
  //4.4.2
  MatrixXd m(3,3);
  m(0,0) = a[0]-b[0];
  m(0,1) = a[0]-c[0];
  m(0,2) = ray.direction[0];
  m(1,0) = a[1]-b[1];
  m(1,1) = a[1]-c[1];
  m(1,2) = ray.direction[1];
  m(2,0) = a[2]-b[2];
  m(2,1) = a[2]-c[2];
  m(2,2) = ray.direction[2];

  MatrixXd r(3,1);
  r(0,0) = a[0]-ray.origin[0];
  r(1,0) = a[1]-ray.origin[1];
  r(2,0) = a[2]-ray.origin[2];

  Eigen::Vector3d solutions = m.colPivHouseholderQr().solve(r);
  double beta = solutions[0];
  double gamma = solutions[1];
  if (gamma <0 || gamma >1) return false;
  if (beta<0 || beta > (1-gamma)) return false;
  double t_temp = solutions[2];
  if (t_temp<min_t) return false;


  t = t_temp;
  
  return true;
  ////////////////////////////////////////////////////////////////////////////
}

