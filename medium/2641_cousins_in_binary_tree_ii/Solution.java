import java.util.LinkedList;
import java.util.Queue;
import nodes.TreeNode;

class Solution {
  public TreeNode replaceValueInTree(TreeNode root) {
    if (root == null) {
      return root;
    }

    final Queue<TreeNode> q = new LinkedList<>();
    q.add(root);

    int levelSum = root.val;

    while (!q.isEmpty()) {
      int nextLevelSum = 0;

      int n = q.size();
      for (; n > 0; --n) {
        final TreeNode node = q.remove();
        node.val = levelSum - node.val;

        int siblingSum = 0;
        siblingSum += (node.left != null ? node.left.val : 0);
        siblingSum += (node.right != null ? node.right.val : 0);

        if (node.left != null) {
          nextLevelSum += node.left.val;
          node.left.val = siblingSum;
          q.add(node.left);
        }
        if (node.right != null) {
          nextLevelSum += node.right.val;
          node.right.val = siblingSum;
          q.add(node.right);
        }
      }

      levelSum = nextLevelSum;
    }

    return root;
  }
}
