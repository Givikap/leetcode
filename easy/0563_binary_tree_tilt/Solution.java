import utils.java.nodes.TreeNode;

class Solution {
  private int tilt;

  public int findTilt(TreeNode root) {
    this.subtreeSum(root);
    return this.tilt;
  }

  private int subtreeSum(TreeNode node) {
    if (node == null) {
      return 0;
    }

    final int leftSum = this.subtreeSum(node.left);
    final int rightSum = this.subtreeSum(node.right);

    this.tilt += Math.abs(leftSum - rightSum);

    return node.val + leftSum + rightSum;
  }
}
