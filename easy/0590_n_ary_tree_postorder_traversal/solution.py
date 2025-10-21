from collections import deque
from typing import List, Optional


class Node:
    def __init__(
        self,
        val: Optional[int] = None,
        children: Optional[List["Node"]] = None,
    ):
        self.val = val
        self.children = children


class Solution:
    def postorder(self, root: Node) -> List[int]:
        if not root:
            return []

        children = []
        queue = deque([root])

        while queue:
            node = queue.popleft()
            children.append(node.val)

            for child in node.children:
                queue.appendleft(child)

        return children[::-1]
