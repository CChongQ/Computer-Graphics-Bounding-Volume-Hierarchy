#include "point_AABBTree_squared_distance.h"
#include <queue> // std::priority_queue

bool point_AABBTree_squared_distance(
	const Eigen::RowVector3d& query,
	const std::shared_ptr<AABBTree>& root,
	const double min_sqrd,
	const double max_sqrd,
	double& sqrd,
	std::shared_ptr<Object>& descendant)
{
	////////////////////////////////////////////////////////////////////////////
	// Replace with your code here
	//pseudocode: assignment web

	//initialize a queue
	std::priority_queue<std::pair< double, std::shared_ptr<Object> >,
		std::vector<std::pair<double, std::shared_ptr<Object>>>,
		std::greater< std::pair<double, std::shared_ptr<Object>>>
	> Q;
	double d_r = point_box_squared_distance(query, root->box);
	Q.push(std::make_pair(d_r, root));

	// initialize minimum distance seen so far
	double d_min = std::numeric_limits<double>::infinity();

	sqrd = d_min;
	bool return_temp = false;

	while (!Q.empty()) {

		double d_s = Q.top().first;
		std::shared_ptr<Object> subtree = Q.top().second;
		Q.pop();

		if (d_s < sqrd) {
			std::shared_ptr<AABBTree> subtree_temp = std::dynamic_pointer_cast<AABBTree>(subtree);

			if (subtree_temp != nullptr) {
				if (subtree_temp->left != nullptr) {
					double d_l = point_box_squared_distance(query, subtree_temp->left->box);
					Q.push(std::make_pair(d_l, subtree_temp->left));
				}
				if (subtree_temp->right != nullptr) {
					double d_r = point_box_squared_distance(query, subtree_temp->right->box);
					Q.push(std::make_pair(d_r, subtree_temp->right));
				}
			}
			else {
				double sqrd_temp;
				std::shared_ptr<Object> descendant_temp;
				bool temp = subtree->point_squared_distance(query, min_sqrd, max_sqrd, sqrd_temp, descendant_temp);
				if (temp) {
					if (sqrd_temp < sqrd) {
						sqrd = sqrd_temp;
						descendant = subtree;
						return_temp = true;
					}
				}
			}
		}
	}

	return return_temp;
	////////////////////////////////////////////////////////////////////////////
}
