class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        len_haystack = len(haystack)
        let_needle = len(needle)

        if let_needle == 0:
            return 0
        if let_needle > len_haystack:
            return -1

        skip = {c: let_needle - i - 1 for i, c in enumerate(needle[:-1])}
        default_skip = let_needle

        i = 0
        while i <= len_haystack - let_needle:
            j = let_needle - 1
            while j >= 0 and haystack[i + j] == needle[j]:
                j -= 1

            if j < 0:
                return i

            mismatch_char = haystack[i + let_needle - 1]
            i += skip.get(mismatch_char, default_skip)

        return -1
