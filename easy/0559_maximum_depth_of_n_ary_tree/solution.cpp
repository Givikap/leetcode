#include "../../utils/cpp/nodes.hpp"
#include <queue>

class Solution {
public:
  int maxDepth(utils::Node *root) {
    if (!root)
      return 0;

    std::queue<utils::Node *> q;
    q.push(root);

    int depth = 0;

    while (!q.empty()) {
      ++depth;
      size_t levelSize = q.size();

      for (size_t _ = 0; _ < levelSize; ++_) {
        utils::Node *node = q.front();
        q.pop();

        for (utils::Node *child : node->children)
          q.push(child);
      }
    }

    return depth;
  }
};
