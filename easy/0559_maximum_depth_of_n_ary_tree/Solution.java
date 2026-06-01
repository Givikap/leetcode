import nodes.Node;

class Solution {
  public int maxDepth(Node root) {
    if (root == null) {
      return 0;
    }

    int maxDepth = 0;

    for (final Node child : root.children) {
      maxDepth = Math.max(maxDepth, maxDepth(child));
    }

    return 1 + maxDepth;
  }
}
