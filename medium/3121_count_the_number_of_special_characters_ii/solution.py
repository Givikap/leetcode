class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        lowercase_chars = "abcdefghijklmnopqrstuvwxyz"
        uppercase_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

        special_chars_count = 0

        for lowercase_c, uppercase_c in zip(lowercase_chars, uppercase_chars):
            lowercase_i = word.rfind(lowercase_c)
            if lowercase_i < 0:
                continue

            uppercase_i = word.find(uppercase_c)
            if uppercase_i < 0:
                continue

            if lowercase_i < uppercase_i:
                special_chars_count += 1

        return special_chars_count
