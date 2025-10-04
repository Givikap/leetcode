from typing import List


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        min_costs = [0] * (len(cost) + 1)

        for i in range(2, len(cost) + 1):
            min_costs[i] = min(
                min_costs[i - 1] + cost[i - 1], min_costs[i - 2] + cost[i - 2]
            )

        return min_costs[-1]
