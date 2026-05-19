class Solution:
    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        word_len = len(word)
        abbr_len = len(abbr)

        word_i = 0
        abbr_i = 0

        while word_i < word_len:
            if abbr[abbr_i].isalpha():
                if word[word_i] != abbr[abbr_i]:
                    return False

                word_i += 1
                abbr_i += 1
            else:
                if abbr[abbr_i] == "0":
                    return False

                jump = 0

                while abbr_i < abbr_len and abbr[abbr_i].isdigit():
                    jump = jump * 10 + ord(abbr[abbr_i]) - 48
                    abbr_i += 1

                word_i += jump

        return word_i == word_len and abbr_i == abbr_len
