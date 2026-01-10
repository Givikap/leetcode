class Solution:
    def maxScore(self, s: str) -> int:
        s = list(map(int, s))

        left = 1 if s[0] == 0 else 0
        right = sum(s) - s[0]

        max_score = 0

        for i in range(len(s) - 1):
            max_score = max(left + right, max_score)

            left += 1 if s[i + 1] == 0 else 0
            right -= s[i + 1]

        return max_score
