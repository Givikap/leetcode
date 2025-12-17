class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        diff = 0

        for c in s + t:
            diff ^= ord(c)

        return chr(diff)
