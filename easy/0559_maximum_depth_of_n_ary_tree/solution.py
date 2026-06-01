from utils.python.nodes import Node


class Solution:
    def maxDepth(self, root: Node) -> int:
        stack = [(root, 1)]

        max_depth = 1

        while stack:
            node, depth = stack.pop()
            max_depth = max(max_depth, depth)

            for child in node.children:
                stack.append((child, depth + 1))

        return max_depth
