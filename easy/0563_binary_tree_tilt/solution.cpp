#include "../../utils/cpp/nodes.hpp"
#include <stack>
#include <unordered_map>

class Solution {
public:
  int findTilt(utils::TreeNode *root) {
    if (!root)
      return 0;

    std::stack<utils::TreeNode *> s1;
    std::stack<utils::TreeNode *> s2;

    s1.push(root);

    while (!s1.empty()) {
      utils::TreeNode *node = s1.top();
      s1.pop();
      s2.push(node);

      if (node->left)
        s1.push(node->left);
      if (node->right)
        s1.push(node->right);
    }

    int tilt = 0;
    std::unordered_map<utils::TreeNode *, int> nodeSums;

    while (!s2.empty()) {
      utils::TreeNode *node = s2.top();
      s2.pop();

      int leftSum = node->left ? nodeSums[node->left] : 0;
      int rightSum = node->right ? nodeSums[node->right] : 0;

      tilt += abs(leftSum - rightSum);
      nodeSums[node] = node->val + leftSum + rightSum;
    }

    return tilt;
  }
};
