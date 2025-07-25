from typing import Optional
from utils.util import TreeNode

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.max_diameter = 0

        def dfs(node):
            if not node:
                return 0
            
            left_height = dfs(node.left)
            right_height = dfs(node.right)

            self.max_diameter = max(self.max_diameter, left_height + right_height)
            return 1 + max(left_height, right_height)

        dfs(root)

        return self.max_diameter