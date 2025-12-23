class Solution:
    def convert(self, s: str, num_rows: int) -> str:
        if num_rows == 1:
            return s

        zigzag_s = []

        for row in range(num_rows):
            for i in range(row, len(s), 2 * num_rows - 2):
                zigzag_s.append(s[i])

                if (
                    row > 0
                    and row < num_rows - 1
                    and 2 * (num_rows - row - 1) + i < len(s)
                ):
                    zigzag_s.append(s[2 * (num_rows - row - 1) + i])

        return "".join(zigzag_s)
