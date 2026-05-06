from typing import Optional

from utils.python.nodes import TreeNode


class Solution:
    def replaceValueInTree(
        self, root: Optional[TreeNode]
    ) -> Optional[TreeNode]:
        root.val = 0

        level = [root]
        while level:
            next_level = []

            for node in level:
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)

            level_sum = 0
            for node in next_level:
                level_sum += node.val

            for node in level:
                level_deduction = 0

                if node.left:
                    level_deduction += node.left.val
                if node.right:
                    level_deduction += node.right.val

                if node.left:
                    node.left.val = level_sum - level_deduction
                if node.right:
                    node.right.val = level_sum - level_deduction

            level = next_level

        return root
