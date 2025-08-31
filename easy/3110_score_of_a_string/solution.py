class Solution:
    def scoreOfString(self, s: str) -> int:
        s_values = [ord(c) for c in s]
        return sum([abs(s_values[i] - s_values[i + 1]) for i in range(len(s) - 1)])
