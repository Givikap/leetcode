#include "../../utils/cpp/nodes.hpp"
#include <deque>
#include <vector>

class Solution {
public:
  std::vector<int> preorder(utils::Node *root) {
    if (!root)
      return {};

    std::vector<int> vals;
    std::deque<utils::Node *> dq = {root};

    while (!dq.empty()) {
      utils::Node *node = dq.front();
      dq.pop_front();

      vals.push_back(node->val);

      for (auto it = node->children.rbegin(); it != node->children.rend(); ++it)
        dq.push_front(*it);
    }

    return vals;
  }
};
