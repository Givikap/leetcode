from typing import List

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left, right = 0, len(numbers) - 1

        while True:
            candidate = numbers[left] + numbers[right]

            if candidate == target:
                return [left + 1, right + 1]
            elif candidate < target:
                left += 1
            else:
                right -= 1