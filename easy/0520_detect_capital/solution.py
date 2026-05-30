class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if len(word) == 1:
            return True

        is_upper = word[0].isupper() and word[1].isupper()

        for i in range(1, len(word)):
            if word[i].islower() == is_upper:
                return False

        return True
