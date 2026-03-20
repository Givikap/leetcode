import heapq
from typing import Optional

from utils.python.nodes import TreeNode


class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        stack = [root]
        values = []

        while stack:
            node = stack.pop()
            values.append(node.val)

            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)

        return heapq.nsmallest(k, values)[-1]
