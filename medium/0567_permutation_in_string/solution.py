from collections import Counter


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        s1_counter = [0] * 26
        s2_window_counter = [0] * 26

        for c1, c2 in zip(s1, s2[: len(s1)]):
            s1_counter[ord(c1) - 97] += 1
            s2_window_counter[ord(c2) - 97] += 1

        if s1_counter == s2_window_counter:
            return True

        for i in range(len(s2) - len(s1)):
            s2_window_counter[ord(s2[i]) - 97] -= 1
            s2_window_counter[ord(s2[i + len(s1)]) - 97] += 1

            if s1_counter == s2_window_counter:
                return True

        return False
