class Solution:
    def numberOfWays(self, corridor: str) -> int:
        section_start = -1
        prev_section_end = -1

        number_of_ways = 1

        for i, item in enumerate(corridor):
            if item != "S":
                continue

            if section_start == -1:
                section_start = i

                if prev_section_end != -1:
                    number_of_ways *= section_start - prev_section_end
            else:
                prev_section_end = i
                section_start = -1

        if section_start != -1:
            return 0
        elif prev_section_end == -1:
            return 0

        return number_of_ways % (10**9 + 7)
