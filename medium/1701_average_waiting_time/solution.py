from typing import List


class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        curr_time = customers[0][0]
        waiting_time = 0

        for arrival, time in customers:
            if curr_time > arrival:
                waiting_time += curr_time - arrival
            else:
                curr_time = arrival

            curr_time += time
            waiting_time += time

        return waiting_time / len(customers)
