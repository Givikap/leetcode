class Solution:
    def numberOfWays(self, corridor: str) -> int:
        sections = []

        section_start = -1
        i = 0

        while i < len(corridor):
            if corridor[i] == "S":
                if section_start == -1:
                    section_start = i
                else:
                    sections.append((section_start, i))
                    section_start = -1

            i += 1

        if section_start != -1:
            return 0
        elif len(sections) < 2:
            return len(sections)

        number_of_ways = 1

        for i in range(len(sections) - 1):
            number_of_ways *= sections[i + 1][0] - sections[i][1]

        return number_of_ways % (10**9 + 7)
