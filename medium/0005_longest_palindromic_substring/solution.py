class Solution:
    def longestPalindrome(self, s: str) -> str:
        s_len = len(s)

        longest_palindrome = s[0]

        for left in range(len(s) - 1):
            for offset in (1, 2):
                right = left + offset

                if right == s_len or s[left] != s[right]:
                    continue

                while (
                    left > 0
                    and right < s_len - 1
                    and s[left - 1] == s[right + 1]
                ):
                    left -= 1
                    right += 1

                if right - left + 1 > len(longest_palindrome):
                    longest_palindrome = s[left : right + 1]

        return longest_palindrome
