#include "../../utils/cpp/nodes.hpp"
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  utils::TreeNode *
  createBinaryTree(std::vector<std::vector<int>> &descriptions) {
    std::unordered_map<int, utils::TreeNode *> nodesMap;
    std::unordered_set<int> parentless;

    for (const std::vector<int> &description : descriptions) {
      int parent = description[0];
      int child = description[1];
      bool isLeft = description[2];

      if (nodesMap.find(parent) == nodesMap.end()) {
        nodesMap[parent] = new utils::TreeNode(parent);
        parentless.insert(parent);
      }

      if (nodesMap.find(child) == nodesMap.end())
        nodesMap[child] = new utils::TreeNode(child);
      if (parentless.find(child) != parentless.end())
        parentless.erase(child);

      if (isLeft)
        nodesMap[parent]->left = nodesMap[child];
      else
        nodesMap[parent]->right = nodesMap[child];
    }

    return nodesMap[*parentless.begin()];
  }
};
