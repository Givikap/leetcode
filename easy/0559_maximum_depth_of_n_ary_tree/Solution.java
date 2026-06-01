import java.util.ArrayDeque;
import java.util.Deque;
import nodes.Node;

class Solution {
  public int maxDepth(Node root) {
    if (root == null) {
      return 0;
    }

    final Deque<Node> dq = new ArrayDeque<>();
    dq.push(root);

    int depth = 0;

    while (!dq.isEmpty()) {
      ++depth;
      final int levelSize = dq.size();

      for (int i = 0; i < levelSize; ++i) {
        for (final Node child : dq.pop().children) {
          dq.add(child);
        }
      }
    }

    return depth;
  }
}
