class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        case_map = [[-1, -1] for _ in range(26)]

        for i, c in enumerate(word):
            if c.isupper():
                c_i = ord(c) - 65

                if case_map[c_i][1] == -1:
                    case_map[c_i][1] = i
            else:
                case_map[ord(c) - 97][0] = i

        special_chars_count = 0

        for last_lowercase_i, first_uppercase_i in case_map:
            if last_lowercase_i != -1 and last_lowercase_i < first_uppercase_i:
                special_chars_count += 1

        return special_chars_count
