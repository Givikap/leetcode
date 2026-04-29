import nodes.TreeNode;

class Solution {
  public TreeNode searchBST(TreeNode root, int val) {
    TreeNode subroot = null;
    TreeNode curr = root;

    while (curr != null) {
      if (curr.val == val) {
        subroot = curr;
        break;
      } else if (curr.val < val) {
        curr = curr.right;
      } else {
        curr = curr.left;
      }
    }

    return subroot;
  }
}
