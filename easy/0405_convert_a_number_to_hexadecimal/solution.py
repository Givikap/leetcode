class Solution:
    def toHex(self, num: int) -> str:
        num_to_hex = {
            **{i: str(i) for i in range(10)},
            10: "a",
            11: "b",
            12: "c",
            13: "d",
            14: "e",
            15: "f",
        }

        if num == 0:
            return "0"
        if num < 0:
            num += 4294967296

        hex_num = []

        while num:
            hex_num.append(num_to_hex[num % 16])
            num //= 16

        return "".join(hex_num[::-1])
