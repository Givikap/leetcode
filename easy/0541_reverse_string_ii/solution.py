class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        reversed_s = []

        start = 0
        end = min(k - 1, len(s) - 1)

        while True:
            for i in range(end, start - 1, -1):
                reversed_s += s[i]

            start = end + 1
            end = min(end + k + 1, len(s))

            if start >= len(s):
                break

            for i in range(start, end):
                reversed_s.append(s[i])

            start = end
            end = min(start + k - 1, len(s) - 1)

        return "".join(reversed_s)
