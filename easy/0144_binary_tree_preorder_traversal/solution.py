from collections import deque
from typing import List, Optional
from utils.nodes import TreeNode

class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        values = []
        if not root:
            return values

        queue = deque([root])

        while queue:
            node = queue.popleft()
            values.append(node.val)

            if node.right:
                queue.appendleft(node.right)
            if node.left:
                queue.appendleft(node.left)

        return values