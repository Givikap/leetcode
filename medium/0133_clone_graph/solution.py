from collections import deque
from typing import Optional

from utils.nodes import Node


class Solution:
    def cloneGraph(self, node: Optional[Node]) -> Optional[Node]:
        if not node:
            return None

        queue = deque([(node, Node(node.val))])
        return_node = queue[0][1]

        nodes_map = {}
        visited_nodes = set([node.val])

        while queue:
            node, cloned_node = queue.popleft()

            nodes_map[node.val] = cloned_node

            for neighbor in node.neighbors:
                if neighbor.val not in nodes_map:
                    nodes_map[neighbor.val] = Node(neighbor.val)

                if neighbor.val not in visited_nodes:
                    queue.append((neighbor, nodes_map[neighbor.val]))
                    visited_nodes.add(neighbor.val)

                cloned_node.neighbors.append(nodes_map[neighbor.val])

        return return_node
