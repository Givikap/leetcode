class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        c_map = {}

        max_length = -1

        for i, c in enumerate(s):
            if c in c_map:
                max_length = max(max_length, i - c_map[c] - 1)
            else:
                c_map[c] = i

        return max_length
