class Solution:
    def convert(self, s: str, num_rows: int) -> str:
        if num_rows == 1:
            return s

        s_len = len(s)
        step = 2 * num_rows - 2

        zigzag_s = []

        for row in range(num_rows):
            for i in range(row, s_len, step):
                zigzag_s.append(s[i])

                if (
                    row > 0
                    and row < num_rows - 1
                    and 2 * (num_rows - row - 1) + i < s_len
                ):
                    zigzag_s.append(s[2 * (num_rows - row - 1) + i])

        return "".join(zigzag_s)
