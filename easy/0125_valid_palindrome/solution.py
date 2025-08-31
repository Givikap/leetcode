class Solution:
    def isPalindrome(self, s: str) -> bool:
        start, end = 0, len(s) - 1

        while start < end:
            while start < end and not s[start].isalnum():
                start += 1

            while end > start and not s[end].isalnum():
                end -= 1

            if start > end:
                return True
            elif s[start].lower() != s[end].lower():
                return False

            start += 1
            end -= 1
