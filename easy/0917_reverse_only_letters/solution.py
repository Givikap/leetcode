class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        sList = list(s)

        left = 0
        right = len(sList) - 1

        while left < right:
            if sList[left].isalpha() and sList[right].isalpha():
                sList[left], sList[right] = sList[right], sList[left]
                left += 1
                right -= 1
            elif sList[left].isalpha():
                right -= 1
            else:
                left += 1

        return "".join(sList)
