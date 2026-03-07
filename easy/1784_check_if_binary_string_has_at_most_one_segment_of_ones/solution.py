class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        has_ones_segment = False

        i = 0
        while i < len(s):
            if s[i] == "1":
                if has_ones_segment:
                    return False

                has_ones_segment = True

                while i + 1 < len(s) and s[i + 1] == "1":
                    i += 1

            i += 1

        return has_ones_segment
