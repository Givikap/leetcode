from typing import List


class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort(reverse=True)
        s.sort(reverse=True)

        cookies_count = 0

        while g and s:
            if g[-1] <= s[-1]:
                g.pop()
                s.pop()
                cookies_count += 1
            else:
                s.pop()

        return cookies_count
