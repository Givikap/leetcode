from typing import List, Optional

from utils.nodes import TreeNode


class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        stack = [([], root)]
        paths = []

        while stack:
            path, node = stack.pop()
            path.append(str(node.val))

            if not node.left and not node.right:
                paths.append("->".join(path))
                continue

            if node.left:
                stack.append((path.copy(), node.left))
            if node.right:
                stack.append((path.copy(), node.right))

        return paths
