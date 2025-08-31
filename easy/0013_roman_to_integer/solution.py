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

        for i in range(len(s)):
            if i + 1 < len(s) and romanToIntMap[s[i]] < romanToIntMap[s[i + 1]]:
                intValue -= romanToIntMap[s[i]]
            else:
                intValue += romanToIntMap[s[i]]

        return intValue
