#include "../../utils/cpp/nodes.hpp"
#include <numeric>
#include <vector>

class Solution {
public:
  int sumRootToLeaf(utils::TreeNode *root) {
    std::vector<std::pair<utils::TreeNode *, int>> stack = {
        std::pair<utils::TreeNode *, int>{root, root->val}};
    std::vector<int> nums;

    while (!stack.empty()) {
      utils::TreeNode *node = stack.back().first;
      int num = stack.back().second;
      stack.pop_back();

      if (!node->left && !node->right) {
        nums.push_back(num);
        continue;
      }

      if (node->left)
        stack.push_back(std::pair<utils::TreeNode *, int>{
            node->left, (num << 1) | node->left->val});
      if (node->right)
        stack.push_back(std::pair<utils::TreeNode *, int>{
            node->right, (num << 1) | node->right->val});
    }

    return reduce(nums.begin(), nums.end(), 0);
  }
};
