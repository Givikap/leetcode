import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;
import nodes.Node;

class Solution {
  public List<Integer> preorder(Node root) {
    final List<Integer> vals = new ArrayList<>();

    if (root == null) {
      return vals;
    }

    final Deque<Node> stack = new ArrayDeque<>();
    stack.push(root);

    while (!stack.isEmpty()) {
      final Node node = stack.pop();

      vals.add(node.val);

      for (final Node child : node.children.reversed()) {
        stack.push(child);
      }
    }

    return vals;
  }
}
