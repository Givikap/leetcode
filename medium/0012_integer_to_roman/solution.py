class Solution:
    def intToRoman(self, num: int) -> str:
        intToRomanPairs = (
            (1000, "M"),
            (900, "CM"),
            (500, "D"),
            (400, "CD"),
            (100, "C"),
            (90, "XC"),
            (50, "L"),
            (40, "XL"),
            (10, "X"),
            (9, "IX"),
            (5, "V"),
            (4, "IV"),
            (1, "I"),
        )

        roman = ""

        for value, symbol in intToRomanPairs:
            while num - value >= 0:
                num -= value
                roman += symbol

        return roman
