class Solution:
    def confusingNumber(self, n: int) -> bool:
        confusing_map = {0: 0, 1: 1, 6: 9, 8: 8, 9: 6}

        n_copy = n
        rotated_n = 0

        while n:
            digit = n_copy % 10

            n_copy //= 10
            rotated_n *= 10

            if digit in confusing_map:
                digit = confusing_map[digit]
            else:
                return False

            rotated_n += digit

        return n != rotated_n
