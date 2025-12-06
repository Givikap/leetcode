class Solution:
    def numWaterBottles(self, num_bottles: int, num_exchanges: int) -> int:
        total_num_bottles = num_empty_bottles = 0

        while num_bottles:
            total_num_bottles += num_bottles
            num_empty_bottles += num_bottles

            num_bottles = num_empty_bottles // num_exchanges
            num_empty_bottles %= num_exchanges

        return total_num_bottles
