class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        sLen = len(s)

        count = 0

        for i in range(sLen - 1):
            if s[i] != s[i + 1]:
                count += 1

                left = i - 1
                right = i + 2

                while (
                    left >= 0
                    and right < sLen
                    and s[left] != s[right]
                    and s[left] == s[left + 1]
                ):
                    count += 1

                    left -= 1
                    right += 1

        return count
