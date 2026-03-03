from typing import Optional

from utils.python.nodes import TreeNode


class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        stack = [(root, [root.val])]
        bin_nums = []

        while stack:
            node, bin_num = stack.pop()

            if not node.left and not node.right:
                bin_nums.append(bin_num)
                continue

            if node.left:
                stack.append((node.left, bin_num + [node.left.val]))
            if node.right:
                stack.append((node.right, bin_num + [node.right.val]))

        nums_sum = 0

        for bin_num in bin_nums:
            num = 0

            for bit in bin_num:
                num = (num << 1) | bit

            nums_sum += num

        return nums_sum
