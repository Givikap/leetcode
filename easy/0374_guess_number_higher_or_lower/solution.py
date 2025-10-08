def guess(num: int) -> int:
    pass


class Solution:
    def guessNumber(self, n: int) -> int:
        left = 1
        right = n

        while left <= right:
            mid = left + (right - left) // 2
            res = guess(mid)

            if res == 0:
                return mid

            if res == 1:
                left = mid + 1
            else:
                right = mid - 1
