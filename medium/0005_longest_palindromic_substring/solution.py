class Solution:
    def longestPalindrome(self, s: str) -> str:
        s_len = len(s)

        longest_palindrome = s[0]

        for i in range(s_len - 1):
            rights = []

            if s[i] == s[i + 1]:
                rights.append(i + 1)
            if i + 2 < s_len and s[i] == s[i + 2]:
                rights.append(i + 2)

            if not rights:
                continue

            for right in rights:
                left = i

                while (
                    left > 0
                    and right < s_len - 1
                    and s[left - 1] == s[right + 1]
                ):
                    left -= 1
                    right += 1

                if len(s[left : right + 1]) > len(longest_palindrome):
                    longest_palindrome = s[left : right + 1]

        return longest_palindrome
