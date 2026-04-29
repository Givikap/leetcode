from typing import List


class Solution:
    def calculateTax(self, brackets: List[List[int]], income: int) -> float:
        tax = 0
        lower = 0

        for upper, percent in brackets:
            bracket_income = min(upper - lower, income)
            lower = upper

            tax += bracket_income * percent * 0.01
            income -= bracket_income

            if income == 0:
                break

        return tax
