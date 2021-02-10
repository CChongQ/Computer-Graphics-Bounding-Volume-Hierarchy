#include "AABBTree.h"
#include <limits>

// See AABBTree.h for API
bool AABBTree::ray_intersect(
    const Ray& ray,
    const double min_t,
    const double max_t,
    double& t,
    std::shared_ptr<Object>& descendant) const
{
    ////////////////////////////////////////////////////////////////////////////
    // Replace with your code here:
     //pseudocode: textbook 12.3.2
    bool ray_interest = ray_intersect_box(ray, this->box, min_t, max_t);
    if (ray_interest) {
        bool left_hit = false;
        bool right_hit = false;
        std::shared_ptr<Object> left_descendant, right_descendant;
        double left_t = std::numeric_limits<double>::infinity();
        double right_t = std::numeric_limits<double>::infinity();

        left_hit = (this->left != NULL) && this->left->ray_intersect(ray, min_t, max_t, left_t, left_descendant);
        right_hit = (this->right != NULL) && this->right->ray_intersect(ray, min_t, max_t, right_t, right_descendant);

        if (left_hit && !left_descendant)
            left_descendant = this->left;
        if (right_hit && !right_descendant)
            right_descendant = this->right;

        if (left_hit && right_hit) {
            if (left_t < right_t) {
                t = left_t;
                descendant = left_descendant;
            }
            else {
                t = right_t;
                descendant = right_descendant;
            }
            return true;
        }
        else if (left_hit) {
            t = left_t;
            descendant = left_descendant;
            return true;
        }
        else if (right_hit) {
            t = right_t;
            descendant = right_descendant;
            return true;
        }
        else
            return false;
    }


    return false;
    ////////////////////////////////////////////////////////////////////////////
}