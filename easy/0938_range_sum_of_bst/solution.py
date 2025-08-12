from typing import Optional
from utils.util import TreeNode

class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        stack = [root]
        rangeSum = 0

        while stack:
            node = stack.pop()

            if low <= node.val and node.val <= high:
                rangeSum += node.val

            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)

        return rangeSum