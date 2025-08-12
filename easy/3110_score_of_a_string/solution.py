class Solution:
    def scoreOfString(self, s: str) -> int:
        sValues = [ord(c) for c in s]
        return sum([abs(sValues[i] - sValues[i+1]) for i in range(len(s) - 1)])