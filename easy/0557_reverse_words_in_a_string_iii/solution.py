class Solution:
    def reverseWords(self, s: str) -> str:
        s_list = list(s)

        i = s.find(" ")
        left = 0

        while i != -1:
            right = i - 1

            while left < right:
                s_list[left], s_list[right] = s_list[right], s_list[left]
                left += 1
                right -= 1

            left = i + 1
            i = s.find(" ", i + 1)

        right = len(s) - 1

        while left < right:
            s_list[left], s_list[right] = s_list[right], s_list[left]
            left += 1
            right -= 1

        return "".join(s_list)
