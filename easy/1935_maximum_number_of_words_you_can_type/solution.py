class Solution:
    def canBeTypedWords(self, text: str, broken_letters: str) -> int:
        broken_letters_set = set(broken_letters)

        words_count = 0

        for word in text.split():
            if set(word).intersection(broken_letters_set):
                continue

            words_count += 1

        return words_count
