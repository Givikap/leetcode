class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        if x < 10:
            return True

        temp = x
        reversed_x = 0

        while temp:
            reversed_x = reversed_x * 10 + temp % 10
            temp //= 10

        return x == reversed_x
