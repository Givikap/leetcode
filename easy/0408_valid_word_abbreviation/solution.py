class Solution:
    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        word_len = len(word)
        abbr_len = len(abbr)

        word_i = 0
        abbr_i = 0

        while word_i < word_len and abbr_i < abbr_len:
            if abbr[abbr_i].isalpha():
                if word[word_i] != abbr[abbr_i]:
                    return False

                word_i += 1
                abbr_i += 1
            else:
                if abbr[abbr_i] == "0":
                    return False

                start_i = abbr_i

                while abbr_i < abbr_len and abbr[abbr_i].isdigit():
                    abbr_i += 1

                word_i += int(abbr[start_i:abbr_i])

        return word_i == word_len and abbr_i == abbr_len
