from typing import Optional

from utils.python.nodes import TreeNode


class Solution:
    def replaceValueInTree(
        self, root: Optional[TreeNode]
    ) -> Optional[TreeNode]:
        stack = [(root, None, 0)]

        while stack:
            level = stack
            stack = []

            level_sum = 0

            for i in range(len(level)):
                level_sum += level[i][0].val

            for i in range(len(level)):
                level[i][0].val = level_sum - level[i][0].val - level[i][2]

            while level:
                node, _, _ = level.pop()

                if node.left:
                    stack.append(
                        (node.left, node, node.right.val if node.right else 0)
                    )
                if node.right:
                    stack.append(
                        (node.right, node, node.left.val if node.left else 0)
                    )

        return root
