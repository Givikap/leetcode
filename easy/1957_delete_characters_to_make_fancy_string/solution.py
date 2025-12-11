class Solution:
    def makeFancyString(self, s: str) -> str:
        fancy_s = []

        prev = None
        prev_count = 0

        for c in s:
            if c == prev:
                prev_count += 1

                if prev_count >= 3:
                    continue
            else:
                prev = c
                prev_count = 1

            fancy_s.append(c)

        return "".join(fancy_s)
