from typing import List, Optional
from utils.nodes import TreeNode

class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        values = []
        
        stack = []
        current = root

        while current or stack:
            while current:
                stack.append(current)
                current = current.left
            
            current = stack.pop()
            values.append(current.val)
            current = current.right

        return values