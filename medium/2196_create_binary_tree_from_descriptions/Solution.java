import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import nodes.TreeNode;

class Solution {
  public TreeNode createBinaryTree(int[][] descriptions) {
    final Map<Integer, TreeNode> nodesMap = new HashMap<>();
    final Set<Integer> parentless = new HashSet<>();

    for (final int[] description : descriptions) {
      final int parent = description[0];
      final int child = description[1];
      final boolean isLeft = description[2] == 1;

      if (!nodesMap.containsKey(parent)) {
        nodesMap.put(parent, new TreeNode(parent));
        parentless.add(parent);
      }

      if (!nodesMap.containsKey(child)) {
        nodesMap.put(child, new TreeNode(child));
      }
      if (parentless.contains(child)) {
        parentless.remove(child);
      }

      if (isLeft) {
        nodesMap.get(parent).left = nodesMap.get(child);
      } else {
        nodesMap.get(parent).right = nodesMap.get(child);
      }
    }

    return nodesMap.get(parentless.iterator().next());
  }
}
