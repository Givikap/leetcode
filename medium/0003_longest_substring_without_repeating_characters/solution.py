from collections import deque


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        substring = deque([])
        visited = set()

        max_length = 0

        for c in s:
            if c in visited:
                while substring[0] != c:
                    visited.remove(substring.popleft())

                visited.remove(substring.popleft())

            substring.append(c)
            visited.add(c)

            if len(visited) > max_length:
                max_length = len(visited)

        return max_length
