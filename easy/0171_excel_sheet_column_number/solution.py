class Solution:
    def titleToNumber(self, column_title: str) -> int:
        column_number = 0

        for i, c in enumerate(column_title[::-1]):
            column_number += (ord(c) - 64) * (26**i)

        return column_number
