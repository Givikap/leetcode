#include "../../utils/cpp/nodes.hpp"
#include <stack>

class Solution {
public:
  int maxDepth(utils::Node *root) {
    if (!root)
      return 0;

    std::stack<std::pair<utils::Node *, int>> s;
    s.push({root, 1});

    int maxDepth = 0;

    while (!s.empty()) {
      utils::Node *node = s.top().first;
      int depth = s.top().second;
      s.pop();

      maxDepth = std::max(maxDepth, depth);

      for (utils::Node *child : node->children)
        s.push({child, depth + 1});
    }

    return maxDepth;
  }
};
