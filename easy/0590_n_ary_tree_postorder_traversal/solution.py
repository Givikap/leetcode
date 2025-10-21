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
        stack = [root]

        while stack:
            node = stack.pop()

            children.append(node.val)
            stack.extend(node.children)

        children.reverse()
        return children
