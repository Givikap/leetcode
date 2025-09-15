from collections import deque


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        substring = deque([])
        visited = set()

        max_length = 0

        for c in s:
            while c in visited:
                visited.remove(substring.popleft())

            substring.append(c)
            visited.add(c)

            max_length = max(max_length, len(substring))

        return max_length
