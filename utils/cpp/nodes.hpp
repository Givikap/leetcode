#include <vector>

namespace utils {

class Node {
public:
  int val;
  std::vector<Node *> children;
  Node() {}
  Node(int _val) : val(_val) {}
  Node(int _val, std::vector<Node *> _children)
      : val(_val), children(_children) {}
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

} // namespace utils
