from collections import Counter
from typing import List, Optional

from utils.python.nodes import TreeNode


class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        vals_counter = Counter()

        stack = [root]
        while stack:
            node = stack.pop()

            vals_counter[node.val] += 1

            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)

        max_count = max(vals_counter.values())

        return [
            val for val, count in vals_counter.items() if count == max_count
        ]
