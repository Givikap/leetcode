from typing import Optional
from utils.nodes import TreeNode

class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False

        stack = [(root, root.val)]

        while stack:
            node, currSum = stack.pop()

            if currSum == targetSum and not node.left and not node.right:
                return True

            if node.left:
                stack.append((node.left, currSum + node.left.val))
            if node.right:
                stack.append((node.right, currSum + node.right.val))

        return False