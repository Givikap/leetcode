from typing import List, Optional
from utils.nodes import TreeNode

class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []

        stack = [root]
        values = []
        
        while stack:
            node = stack.pop()
            values.append(node.val)

            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)
        
        return values[::-1]