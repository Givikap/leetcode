from typing import List, Optional
from utils.nodes import TreeNode

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        mid = len(nums) // 2

        root = TreeNode(val=nums[mid])
        stack = [(root, 0, nums[:mid]), (root, 1, nums[mid+1:])]

        while stack:
            node, side, nums, = stack.pop()

            if not nums:
                continue

            mid = len(nums) // 2

            if side == 0:
                node.left = node = TreeNode(val=nums[mid])
            else:
                node.right = node = TreeNode(val=nums[mid])
            
            stack.extend([(node, 0, nums[:mid]), (node, 1, nums[mid+1:])])

        return root