from typing import List, Optional
from utils.util import TreeNode

class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        level_nodes = [root]
        level_averages = []

        while level_nodes:
            new_level_nodes = []
            level_values = []

            for node in level_nodes:
                level_values.append(node.val)
                
                if node.left:
                    new_level_nodes.append(node.left)
                if node.right:
                    new_level_nodes.append(node.right)

            level_nodes = new_level_nodes
            level_averages.append(sum(level_values) / len(level_values))

        return level_averages