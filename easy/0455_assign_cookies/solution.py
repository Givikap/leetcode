from typing import List


class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()

        g_len = len(g)
        s_len = len(s)
        g_i = s_i = 0

        cookies_count = 0

        while g_i < g_len and s_i < s_len:
            if g[g_i] <= s[s_i]:
                g_i += 1
                cookies_count += 1

            s_i += 1

        return cookies_count
