class Solution:
    def minOperations(self, s: str) -> int:
        if len(s) == 1:
            return 0
        if len(s) == 2:
            return int(s[0] == s[1])

        changes_count = 0
        zero = False

        for i in range(len(s)):
            if (not zero and s[i] != "0") or (zero and s[i] != "1"):
                changes_count += 1

            zero = not zero

        return min(changes_count, len(s) - changes_count)
