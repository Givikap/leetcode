from typing import Optional
from utils.util import TreeNode

class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return root

        stack = [root]

        while stack:
            curr = stack.pop()
            curr.left, curr.right = curr.right, curr.left

            if curr.left:
                stack.append(curr.left)
            if curr.right:
                stack.append(curr.right)

        return root