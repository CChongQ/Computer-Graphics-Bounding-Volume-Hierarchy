#include "find_all_intersecting_pairs_using_AABBTrees.h"
#include "box_box_intersect.h"
// Hint: use a list as a queue
#include <list> 

void find_all_intersecting_pairs_using_AABBTrees(
	const std::shared_ptr<AABBTree>& rootA,
	const std::shared_ptr<AABBTree>& rootB,
	std::vector<std::pair<std::shared_ptr<Object>, std::shared_ptr<Object> > >&
	leaf_pairs)
{
	////////////////////////////////////////////////////////////////////////////
	// Add your code here
	//pseudocode: assignment web
	std::list<std::pair<std::shared_ptr<Object>, std::shared_ptr<Object>>> Q;

	bool A_in_B = box_box_intersect(rootA->box, rootB->box);
	if (A_in_B)
		Q.push_back(std::make_pair(rootA, rootB));

	while (!Q.empty()) {
		std::shared_ptr<Object> nodeA = Q.front().first;
		std::shared_ptr<Object> nodeB = Q.front().second;
		Q.pop_front();

		std::shared_ptr<AABBTree> nodeA_temp = std::dynamic_pointer_cast<AABBTree>(nodeA);
		std::shared_ptr<AABBTree> nodeB_temp = std::dynamic_pointer_cast<AABBTree>(nodeB);

		if (!nodeA_temp && !nodeB_temp) {
			leaf_pairs.push_back(std::make_pair(nodeA, nodeB));
		}
		else if (!nodeA_temp) {
			if ( box_box_intersect(nodeA->box, nodeB_temp->left->box))
				Q.push_back(std::make_pair(nodeA, nodeB_temp->left));
			if ( box_box_intersect(nodeA->box, nodeB_temp->right->box))
				Q.push_back(std::make_pair(nodeA, nodeB_temp->right));
		}
		else if (!nodeB_temp) {
			if ( box_box_intersect(nodeA_temp->left->box, nodeB->box))
				Q.push_back(std::make_pair(nodeA_temp->left, nodeB));

			if (box_box_intersect(nodeA_temp->right->box, nodeB->box))
				Q.push_back(std::make_pair(nodeA_temp->right, nodeB));
		}
		else {
			if (box_box_intersect(nodeA_temp->left->box, nodeB_temp->left->box))
				Q.push_back(std::make_pair(nodeA_temp->left, nodeB_temp->left));

			if (box_box_intersect(nodeA_temp->left->box, nodeB_temp->right->box))
				Q.push_back(std::make_pair(nodeA_temp->left, nodeB_temp->right));

			if (box_box_intersect(nodeA_temp->right->box, nodeB_temp->right->box))
				Q.push_back(std::make_pair(nodeA_temp->right, nodeB_temp->right));

			if (box_box_intersect(nodeA_temp->right->box, nodeB_temp->left->box))
				Q.push_back(std::make_pair(nodeA_temp->right, nodeB_temp->left));
		}
	}


	////////////////////////////////////////////////////////////////////////////
}