#include "../../utils/cpp/nodes.hpp"
#include <stack>
#include <vector>

class Solution {
public:
  std::vector<int> preorder(utils::Node *root) {
    if (!root)
      return {};

    std::vector<int> vals;

    std::stack<utils::Node *> s;
    s.push(root);

    while (!s.empty()) {
      utils::Node *node = s.top();
      s.pop();

      vals.push_back(node->val);

      for (auto it = node->children.rbegin(); it != node->children.rend(); ++it)
        s.push(*it);
    }

    return vals;
  }
};
