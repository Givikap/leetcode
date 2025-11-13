from typing import List


class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        for word in words:
            start, end = 0, len(word) - 1

            while True:
                if start > end:
                    return word
                elif word[start] != word[end]:
                    break

                start += 1
                end -= 1

        return ""
