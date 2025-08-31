from typing import Optional

from utils.nodes import TreeNode


class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not subRoot:
            return True
        if not root:
            return False

        def isSameTree(r1: TreeNode, r2: TreeNode):
            stack = [(r1, r2)]

            while stack:
                n1, n2 = stack.pop()

                if not n1 and not n2:
                    continue

                if (not n1 or not n2) or (n1.val != n2.val):
                    return False

                stack.append((n1.left, n2.left))
                stack.append((n1.right, n2.right))

            return True

        stack = [root]
        while stack:
            node = stack.pop()

            if node.val == subRoot.val:
                if isSameTree(node, subRoot):
                    return True

            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)

        return False
