class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x

        left, right = 2, x // 2

        while left <= right:
            mid = (right + left) // 2
            mid_sqrt = mid**2

            if mid_sqrt == x:
                return mid
            elif mid_sqrt < x:
                left = mid + 1
            else:
                right = mid - 1

        return right
