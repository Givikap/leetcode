class Solution:
    def romanToInt(self, s: str) -> int:
        roman_to_int_map = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
        }

        int_value = 0
        i = 0

        for i in range(len(s)):
            if (
                i + 1 < len(s)
                and roman_to_int_map[s[i]] < roman_to_int_map[s[i + 1]]
            ):
                int_value -= roman_to_int_map[s[i]]
            else:
                int_value += roman_to_int_map[s[i]]

        return int_value
