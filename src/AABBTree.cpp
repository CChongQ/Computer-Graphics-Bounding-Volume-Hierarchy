#include "AABBTree.h"
#include "insert_box_into_box.h"

AABBTree::AABBTree(
  const std::vector<std::shared_ptr<Object> > & objects,
  int a_depth): 
  depth(std::move(a_depth)), 
  num_leaves(objects.size())
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  //pseudocode: textbook 12.3.2
  int N = objects.size();
  
  if (N == 0){
    this->left = NULL;
    this->right = NULL;
  }
  else if (N == 1){
    this->left = objects[0];
    this->right = NULL;
    insert_box_into_box(objects[0]->box, this->box);
  }
  else if (N == 2){
    this->left = objects[0];
    this->right = objects[1];
    insert_box_into_box(objects[0]->box, this->box);
    insert_box_into_box(objects[1]->box, this->box);
  }
  else{
    for (int i = 0; i<N ; i++){
       insert_box_into_box(objects[i]->box, this->box);
    }

    //find midpoint
    double longest_distance = -1;
    double axis_i = -1;
    for (int i = 0; i<3 ; i++){
      double distance = this->box.max_corner[i] - this->box.min_corner[i];
      if (distance > longest_distance){
        longest_distance = distance;
        axis_i = i;
      }
    }
    double midpoint = (this->box.max_corner[axis_i] - this->box.min_corner[axis_i])/2;

    //partition A into list with length k and (N-k) surrounding midpoint
    std::vector<std::shared_ptr<Object>> left_list;
    std::vector<std::shared_ptr<Object>> right_list;
    for (int i=0; i<N; i++){
      if (objects[i]->box.center()[axis_i] < midpoint){
        left_list.push_back(objects[i]);
      }
      else{
        right_list.push_back(objects[i]);
      }
    }

    if (left_list.empty() && !right_list.empty()){
      this->left = right_list.back();
      right_list.pop_back();
    }
    else if (right_list.empty() && !left_list.empty()){
      this->right = left_list.back();
      left_list.pop_back();
    }
    else{
      this->left = std::make_shared<AABBTree>(left_list,a_depth+1);
      this->right = std::make_shared<AABBTree>(right_list,a_depth+1);
    }

  }


  ////////////////////////////////////////////////////////////////////////////
}
