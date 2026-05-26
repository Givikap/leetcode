class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        case_map = [0] * 26

        special_chars_count = 0

        for c in word:
            if c.isupper():
                c_i = ord(c) - 65
                case_map[c_i] |= 1
            else:
                c_i = ord(c) - 97
                case_map[c_i] |= 2

            if case_map[c_i] == 3:
                case_map[c_i] = 7
                special_chars_count += 1

        return special_chars_count
