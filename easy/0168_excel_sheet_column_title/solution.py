class Solution:
    def convertToTitle(self, column_number: int) -> str:
        column_title = ""

        while column_number:
            column_title = chr((column_number - 1) % 26 + 65) + column_title
            column_number = (column_number - 1) // 26

        return column_title
