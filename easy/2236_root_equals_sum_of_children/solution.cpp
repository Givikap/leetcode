using namespace std;

#include "../../utils/cpp/nodes.hpp"

class Solution {
public:
  bool checkTree(TreeNode *root) {
    return root->val == root->left->val + root->right->val;
  }
};
