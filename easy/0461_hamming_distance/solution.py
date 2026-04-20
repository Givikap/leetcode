class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        z = x ^ y
        hamming_distance = 0

        while z:
            hamming_distance += z & 1
            z >>= 1

        return hamming_distance
