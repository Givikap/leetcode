class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        s = list(s)

        start = 0
        end = min(k - 1, len(s) - 1)

        while True:
            left = start
            right = end

            while left < right:
                s[left], s[right] = s[right], s[left]
                left += 1
                right -= 1

            start = start + 2 * k
            end = min(start + k - 1, len(s) - 1)

            if start >= len(s):
                break

        return "".join(s)
