from typing import Optional

from utils.nodes import Node


class Solution:
    def cloneGraph(self, node: Optional[Node]) -> Optional[Node]:
        if not node:
            return None

        stack = [node]
        nodes_map = {node.val: Node(node.val)}

        while stack:
            original_node = stack.pop()
            cloned_node = nodes_map[original_node.val]

            for neighbor in original_node.neighbors:
                if neighbor.val not in nodes_map:
                    stack.append(neighbor)
                    nodes_map[neighbor.val] = Node(neighbor.val)

                cloned_node.neighbors.append(nodes_map[neighbor.val])

        return nodes_map[node.val]
