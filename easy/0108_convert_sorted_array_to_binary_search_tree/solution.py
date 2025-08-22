from typing import List, Optional
from utils.nodes import TreeNode

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        mid = len(nums) // 2

        root = TreeNode(val=nums[mid])
        stack = [(root, nums[:mid], nums[mid+1:])]

        while stack:
            node, left, right = stack.pop()

            if left:
                mid = len(left) // 2

                node.left = TreeNode(val=left[mid])
                stack.append((node.left, left[:mid], left[mid+1:]))
            if right:
                mid = len(right) // 2

                node.right = TreeNode(val=right[mid])
                stack.append((node.right, right[:mid], right[mid+1:]))

        return root