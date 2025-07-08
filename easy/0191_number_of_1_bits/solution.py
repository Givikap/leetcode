class Solution:
    def hammingWeight(self, n: int) -> int:
        one_bits_counter = 0

        while n != 0:
            if n % 2 == 1:
                one_bits_counter += 1

            n //= 2

        return one_bits_counter