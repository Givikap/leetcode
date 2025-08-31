class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x

        left, right = 2, x // 2

        while left <= right:
            mid = (right + left) // 2
            midSqrt = mid**2

            if midSqrt == x:
                return mid
            elif midSqrt < x:
                left = mid + 1
            else:
                right = mid - 1

        return right
