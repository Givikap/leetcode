class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        lastAbcMap = [-1] * 3
        substringsCount = 0

        for i, c in enumerate(s):
            lastAbcMap[ord(c) - 97] = i
            substringsCount += min(lastAbcMap) + 1

        return substringsCount
