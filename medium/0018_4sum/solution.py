from typing import List


class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()

        four_sums = []

        for outer_left in range(len(nums) - 3):
            for outer_right in range(len(nums) - 1, outer_left + 2, -1):
                inner_left = outer_left + 1
                inner_right = outer_right - 1

                while inner_left < inner_right:
                    curr_sum = (
                        nums[outer_left]
                        + nums[inner_left]
                        + nums[inner_right]
                        + nums[outer_right]
                    )

                    if curr_sum == target:
                        four_sums.append(
                            (
                                nums[outer_left],
                                nums[inner_left],
                                nums[inner_right],
                                nums[outer_right],
                            )
                        )

                    if curr_sum < target:
                        inner_left += 1
                    elif curr_sum > target:
                        inner_right -= 1
                    else:
                        inner_left += 1
                        inner_right -= 1

        return list(map(list, set(four_sums)))
