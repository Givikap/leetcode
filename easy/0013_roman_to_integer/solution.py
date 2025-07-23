class Solution:
    def romanToInt(self, s: str) -> int:
        romanToIntMap = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
        }

        intValue = 0
        i = 0

        while i < len(s):
            if s[i] == "I" and i + 1 < len(s) and s[i+1] in ("V", "X"):
                intValue += romanToIntMap[s[i+1]] - romanToIntMap["I"]
            elif s[i] == "X" and i + 1 < len(s) and s[i+1] in ("L", "C"):
                intValue += romanToIntMap[s[i+1]] - romanToIntMap["X"]
            elif s[i] == "C" and i + 1 < len(s) and s[i+1] in ("D", "M"):
                intValue += romanToIntMap[s[i+1]] - romanToIntMap["C"]
            else:
                intValue += romanToIntMap[s[i]]
                i -= 1

            i += 2

        return intValue  