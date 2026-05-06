#include "../../utils/cpp/nodes.hpp"
#include <vector>

class Solution {
public:
  utils::TreeNode *replaceValueInTree(utils::TreeNode *root) {
    root->val = 0;

    std::vector<utils::TreeNode *> level = {root};
    while (!level.empty()) {
      std::vector<utils::TreeNode *> nextLevel;

      for (const utils::TreeNode *node : level) {
        if (node->left)
          nextLevel.push_back(node->left);
        if (node->right)
          nextLevel.push_back(node->right);
      }

      int levelSum = 0;
      for (const utils::TreeNode *node : nextLevel)
        levelSum += node->val;

      for (const utils::TreeNode *node : level) {
        int levelDeduction = 0;

        if (node->left)
          levelDeduction += node->left->val;
        if (node->right)
          levelDeduction += node->right->val;

        if (node->left)
          node->left->val = levelSum - levelDeduction;
        if (node->right)
          node->right->val = levelSum - levelDeduction;
        ;
      }

      level = nextLevel;
    }

    return root;
  }
};
