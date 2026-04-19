class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        for end in range(1, len(s)):
            if len(s) % end != 0:
                continue

            if s[:end] * (len(s) // end) == s:
                return True

        return False
