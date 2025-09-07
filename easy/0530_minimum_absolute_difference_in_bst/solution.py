from typing import Optional

from utils.nodes import TreeNode


class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        stack = []
        values = []

        curr = root

        while stack or curr:
            while curr:
                stack.append(curr)
                curr = curr.left

            curr = stack.pop()
            values.append(curr.val)
            curr = curr.right

        return min(
            [abs(values[i] - values[i + 1]) for i in range(len(values) - 1)]
        )
