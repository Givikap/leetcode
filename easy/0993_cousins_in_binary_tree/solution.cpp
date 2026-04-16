#include "../../utils/cpp/nodes.hpp"
#include <tuple>
#include <unordered_map>
#include <vector>

class Solution {
public:
  bool isCousins(utils::TreeNode *root, int x, int y) {
    std::unordered_map<int, int> depths;
    std::unordered_map<int, int> parents;

    std::vector<std::tuple<utils::TreeNode *, int, int>> s = {{root, 0, -1}};
    while (!s.empty()) {
      utils::TreeNode *node = std::get<0>(s.back());
      int depth = std::get<1>(s.back());
      int parent = std::get<2>(s.back());

      s.pop_back();

      depths[node->val] = depth;
      parents[node->val] = parent;

      if (node->left)
        s.push_back({node->left, depth + 1, node->val});
      if (node->right)
        s.push_back({node->right, depth + 1, node->val});
    }

    return depths[x] == depths[y] && parents[x] != parents[y];
  }
};
