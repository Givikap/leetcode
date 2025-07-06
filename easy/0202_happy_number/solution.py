class Solution:
    def isHappy(self, n: int) -> bool:
        visited = set()

        while True:
            digit_square_sum = sum([int(digit) ** 2 for digit in str(n)])

            if digit_square_sum == 1:
                return True
            elif digit_square_sum in visited:
                return False

            n = digit_square_sum
            visited.add(digit_square_sum)

        return False