from collections import deque
from typing import List

from utils.python.nodes import Node


class Solution:
    def preorder(self, root: "Node") -> List[int]:
        if not root:
            return []

        vals = []
        dq = deque([root])

        while dq:
            node = dq.popleft()

            vals.append(node.val)

            for child in reversed(node.children):
                dq.appendleft(child)

        return vals
