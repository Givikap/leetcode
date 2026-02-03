using namespace std;

#include "../../utils/cpp/nodes.hpp"
#include <vector>

class Solution {
public:
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    vector<int> leafs1, leafs2;

    TreeNode *node;

    for (auto &[root, leafs] : vector<pair<TreeNode *, vector<int> *>>{
             {root1, &leafs1}, {root2, &leafs2}}) {
      vector<TreeNode *> stack = {root};

      while (!stack.empty()) {
        node = stack.back();
        stack.pop_back();

        if (!node->left && !node->right) {
          leafs->push_back(node->val);
          continue;
        }

        if (node->left)
          stack.push_back(node->left);
        if (node->right)
          stack.push_back(node->right);
      }
    }

    return leafs1 == leafs2;
  }
};
