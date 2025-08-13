from typing import List

class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        twoCheapestChocoPrice = sum(sorted(prices)[:2])
        
        if twoCheapestChocoPrice <= money:
            return money - twoCheapestChocoPrice
        else:
            return money