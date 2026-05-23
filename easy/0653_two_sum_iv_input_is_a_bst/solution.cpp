#include "../../utils/cpp/nodes.hpp"
#include <stack>
#include <unordered_set>

class Solution {
public:
  bool findTarget(utils::TreeNode *root, int k) {
    std::unordered_set<int> visited;

    std::stack<utils::TreeNode *> s;
    s.push(root);

    while (!s.empty()) {
      utils::TreeNode *node = s.top();
      s.pop();

      if (visited.find(k - node->val) != visited.end())
        return true;
      else
        visited.insert(node->val);

      if (node->left)
        s.push(node->left);
      if (node->right)
        s.push(node->right);
    }

    return false;
  }
};
