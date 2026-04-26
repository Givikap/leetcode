from typing import List


class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        nums_len = len(nums)

        four_sums = []

        for outer_left in range(nums_len - 3):
            if outer_left > 0 and nums[outer_left] == nums[outer_left - 1]:
                continue

            if (
                nums[outer_left]
                + nums[outer_left + 1]
                + nums[outer_left + 2]
                + nums[outer_left + 3]
                > target
            ):
                break
            if nums[outer_left] + nums[-3] + nums[-2] + nums[-1] < target:
                continue

            for outer_right in range(nums_len - 1, outer_left + 2, -1):
                if (
                    outer_right < nums_len - 1
                    and nums[outer_right] == nums[outer_right + 1]
                ):
                    continue

                inner_left = outer_left + 1
                inner_right = outer_right - 1

                outer_sum = nums[outer_left] + nums[outer_right]

                while inner_left < inner_right:
                    curr_sum = outer_sum + nums[inner_left] + nums[inner_right]

                    if curr_sum == target:
                        four_sums.append(
                            (
                                nums[outer_left],
                                nums[inner_left],
                                nums[inner_right],
                                nums[outer_right],
                            )
                        )

                        while (
                            inner_left < inner_right
                            and nums[inner_left] == nums[inner_left + 1]
                        ):
                            inner_left += 1
                        while (
                            inner_left < inner_right
                            and nums[inner_right] == nums[inner_right - 1]
                        ):
                            inner_right -= 1

                        inner_left += 1
                        inner_right -= 1
                    elif curr_sum < target:
                        inner_left += 1
                    else:
                        inner_right -= 1

        return four_sums
