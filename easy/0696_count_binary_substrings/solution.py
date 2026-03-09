class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        count = 0

        prev = 0
        curr = 1

        for i in range(len(s) - 1):
            if s[i] == s[i + 1]:
                curr += 1
            else:
                count += min(curr, prev)
                prev = curr
                curr = 1

        return count + min(curr, prev)
