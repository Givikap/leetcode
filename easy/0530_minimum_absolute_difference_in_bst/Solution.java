import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;
import utils.java.nodes.TreeNode;

class Solution {
  public int getMinimumDifference(TreeNode root) {
    final Deque<TreeNode> stack = new ArrayDeque<>();
    final List<Integer> values = new ArrayList<>();

    TreeNode curr = root;

    while (!stack.isEmpty() || curr != null) {
      while (curr != null) {
        stack.push(curr);
        curr = curr.left;
      }

      curr = stack.pop();

      values.add(curr.val);
      curr = curr.right;
    }

    int minDiff = Integer.MAX_VALUE;
    for (int i = 0; i < values.size() - 1; ++i) {
      minDiff = Math.min(minDiff, Math.abs(values.get(i) - values.get(i + 1)));
    }

    return minDiff;
  }
}
