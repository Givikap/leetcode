class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        difference = [i for i in range(len(s1)) if s1[i] != s2[i]]

        return len(difference) == 0 or (
            len(difference) == 2
            and s1[difference[0]] == s2[difference[1]]
            and s1[difference[1]] == s2[difference[0]]
        )
