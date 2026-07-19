#include "../../utils/cpp/nodes.hpp"

class Solution {
public:
  int findTilt(utils::TreeNode *root) {
    int tilt = 0;
    subtreeSum(root, tilt);
    return tilt;
  }

private:
  int subtreeSum(utils::TreeNode *node, int &tilt) {
    if (!node)
      return 0;

    int leftSum = subtreeSum(node->left, tilt);
    int rightSum = subtreeSum(node->right, tilt);

    tilt += abs(leftSum - rightSum);

    return node->val + leftSum + rightSum;
  }
};
