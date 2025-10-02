from typing import List


class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        bills_tracker = [0, 0]

        for bill in bills:
            if bill == 5:
                bills_tracker[0] += 1
                continue

            if bill == 10:
                bills_tracker[1] += 1

            if bill == 20 and bills_tracker[1]:
                bill -= 10
                bills_tracker[1] -= 1

            while bills_tracker[0] and bill > 5:
                bill -= 5
                bills_tracker[0] -= 1

            if bill > 5:
                return False

        return True
