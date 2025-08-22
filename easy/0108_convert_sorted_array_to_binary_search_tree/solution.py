from typing import List, Optional
from utils.nodes import TreeNode

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        mid = len(nums) // 2

        root = TreeNode(val=nums[mid])

        if mid > 0:
            root.left = self.sortedArrayToBST(nums[:mid])
        if mid + 1 < len(nums):
            root.right = self.sortedArrayToBST(nums[mid+1:])

        return root