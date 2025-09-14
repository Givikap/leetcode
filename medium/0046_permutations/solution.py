from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        permutations = []

        def backtrack(permutation: List[int], explored: List[int]):
            if len(permutation) == len(nums):
                permutations.append(permutation)
                return

            for i in range(len(nums)):
                if explored[i]:
                    continue

                explored[i] = True
                backtrack(permutation + [nums[i]], explored)
                explored[i] = False

        backtrack([], [False] * len(nums))

        return permutations
