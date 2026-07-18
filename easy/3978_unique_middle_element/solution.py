class Solution:
    def isMiddleElementUnique(self, nums: list[int]) -> bool:
        left = 0
        right = len(nums) - 1

        midNum = nums[len(nums) // 2]

        while left < right:
            if nums[left] == midNum or nums[right] == midNum:
                return False

            left += 1
            right -= 1

        return True
