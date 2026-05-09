class Solution:
    def reverseByType(self, s: str) -> str:
        chars = list(s)

        for should_be_lower_case in (True, False):
            left = 0
            right = len(s) - 1

            while True:
                while (
                    left < right
                    and chars[left].islower() == should_be_lower_case
                ):
                    left += 1
                while (
                    right > 0
                    and chars[right].islower() == should_be_lower_case
                ):
                    right -= 1

                if left >= right:
                    break

                chars[left], chars[right] = chars[right], chars[left]

                left += 1
                right -= 1

        return "".join(chars)
