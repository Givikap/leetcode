class Solution:
    def minOperations(self, s: str) -> int:
        if len(s) == 1:
            return 0
        if len(s) == 2:
            return int(s[0] == s[1])

        zeros = ones = 0
        zero = True

        for i in range(len(s)):
            if (zero and s[i] != "0") or (not zero and s[i] != "1"):
                zeros += 1
            if (zero and s[i] != "1") or (not zero and s[i] != "0"):
                ones += 1

            zero = not zero

        return min(zeros, ones)
