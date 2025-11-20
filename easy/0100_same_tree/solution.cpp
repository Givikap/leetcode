using namespace std;

#include "../../utils/cpp/nodes.hpp"
#include <vector>

class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    vector<pair<TreeNode *, TreeNode *>> stack = {{p, q}};
    pair<TreeNode *, TreeNode *> pair;

    while (!stack.empty()) {
      pair = stack.back();
      stack.pop_back();

      if (!pair.first && !pair.second)
        continue;
      else if (!(pair.first && pair.second))
        return false;
      else if (pair.first->val != pair.second->val)
        return false;
      else {
        stack.push_back({pair.first->left, pair.second->left});
        stack.push_back({pair.first->right, pair.second->right});
      }
    }

    return true;
  }
};
