class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        s_len = len(s)
        t_len = len(t)

        si = ti = 0

        while si < s_len and ti < t_len:
            if s[si] == t[ti]:
                ti += 1

            si += 1

        return t_len - ti
