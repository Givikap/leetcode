#include "../../utils/cpp/nodes.hpp"
#include <queue>

class Solution {
public:
  utils::TreeNode *replaceValueInTree(utils::TreeNode *root) {
    if (!root)
      return root;

    std::queue<utils::TreeNode *> q;
    q.push(root);

    int levelSum = root->val;

    while (!q.empty()) {
      int nextLevelSum = 0;

      size_t n = q.size();
      for (; n > 0; --n) {
        utils::TreeNode *node = q.front();
        q.pop();

        node->val = levelSum - node->val;

        int siblingSum = 0;
        siblingSum += (node->left ? node->left->val : 0);
        siblingSum += (node->right ? node->right->val : 0);

        if (node->left) {
          nextLevelSum += node->left->val;
          node->left->val = siblingSum;
          q.push(node->left);
        }
        if (node->right) {
          nextLevelSum += node->right->val;
          node->right->val = siblingSum;
          q.push(node->right);
        }
      }

      levelSum = nextLevelSum;
    }

    return root;
  }
};
