class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        sLen = len(s)

        abcCounter = [0] * 3
        right = 0

        substringsCount = 0

        for left in range(sLen - 2):
            while right < sLen:
                abcCounter[ord(s[right]) - 97] += 1
                right += 1

                if abcCounter[0] and abcCounter[1] and abcCounter[2]:
                    break

            if not (abcCounter[0] and abcCounter[1] and abcCounter[2]):
                break

            substringsCount += sLen - right + 1

            abcCounter[ord(s[left]) - 97] -= 1
            while abcCounter[0] and abcCounter[1] and abcCounter[2]:
                right -= 1
                abcCounter[ord(s[right]) - 97] -= 1

        return substringsCount
