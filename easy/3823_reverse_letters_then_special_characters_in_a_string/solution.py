class Solution:
    def reverseByType(self, s: str) -> str:
        lowercase_letters = []
        special_chars = []

        for i in range(len(s) - 1, -1, -1):
            if s[i].islower():
                lowercase_letters.append(i)
            else:
                special_chars.append(i)

        lowercase_i = 0
        special_i = 0

        reversed_chars = []

        for i in range(len(s)):
            if s[i].islower():
                reversed_chars.append(s[lowercase_letters[lowercase_i]])
                lowercase_i += 1
            else:
                reversed_chars.append(s[special_chars[special_i]])
                special_i += 1

        return "".join(reversed_chars)
