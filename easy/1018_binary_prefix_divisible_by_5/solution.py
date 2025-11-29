from typing import List


class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        bin_num = 0
        answer = []

        for i in range(len(nums)):
            bin_num = (bin_num << 1) | nums[i]
            answer.append(bin_num % 5 == 0)

        return answer
