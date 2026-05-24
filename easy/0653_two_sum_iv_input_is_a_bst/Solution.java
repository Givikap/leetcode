import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;
import nodes.TreeNode;

class Solution {
  public boolean findTarget(TreeNode root, int k) {
    TreeNode curr = root;

    final Deque<TreeNode> stack = new ArrayDeque<>();
    final List<Integer> sortedVals = new ArrayList<>();

    while (curr != null || !stack.isEmpty()) {
      while (curr != null) {
        stack.push(curr);
        curr = curr.left;
      }

      final TreeNode node = stack.pop();

      sortedVals.add(node.val);
      curr = node.right;
    }

    int left = 0;
    int right = sortedVals.size() - 1;

    while (left < right) {
      final int currSum = sortedVals.get(left) + sortedVals.get(right);

      if (currSum == k) {
        return true;
      } else if (currSum < k) {
        ++left;
      } else {
        --right;
      }
    }

    return false;
  }
}
