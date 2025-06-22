from typing import List

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        subsets_list = [[]]

        for i in range(len(nums)):
            start = last_size if i > 0 and nums[i-1] == nums[i] else 0
            last_size = len(subsets_list)  

            for j in range(start, len(subsets_list)):
                subsets_list.append(subsets_list[j] + [nums[i]])
        
        return subsets_list