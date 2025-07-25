from typing import List

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        if nums[0] >= 0:
            return [num**2 for num in nums]
        if nums[-1] <= 0:
            return [num**2 for num in nums[::-1]]

        positive = 0
        while nums[positive] < 0 and positive < len(nums) - 1:
            positive += 1

        nums = [num**2 for num in nums]
        negativeNums = nums[:positive]

        for i in range(len(nums)):
            if not negativeNums or (positive < len(nums) and nums[positive] < negativeNums[-1]):
                nums[i] = nums[positive]
                positive += 1
            else:
                nums[i] = negativeNums.pop()

        return nums