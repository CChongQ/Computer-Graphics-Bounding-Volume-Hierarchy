#include "nearest_neighbor_brute_force.h"
#include <limits>// std::numeric_limits<double>::infinity();
#include <math.h> 

void nearest_neighbor_brute_force(
    const Eigen::MatrixXd& points,
    const Eigen::RowVector3d& query,
    int& I,
    double& sqrD)
{
    ////////////////////////////////////////////////////////////////////////////
    // Replace with your code here:
    double nearest_dis = std::numeric_limits<double>::infinity();
    double nearest_I = -1;
    for (int i = 0; i < points.rows(); i++) {
        double dis_current = pow(query[0] - points(i, 0), 2) + pow(query[1] - points(i, 1), 2) + pow(query[2] - points(i, 2), 2);
        if (dis_current < nearest_dis) {
            nearest_dis = dis_current;
            nearest_I = i;
        }
    }
    I = nearest_I;
    sqrD = nearest_dis;

    ////////////////////////////////////////////////////////////////////////////
}