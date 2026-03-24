class Solution:
    def reformatDate(self, date: str) -> str:
        months_map = {
            "Jan": 1,
            "Feb": 2,
            "Mar": 3,
            "Apr": 4,
            "May": 5,
            "Jun": 6,
            "Jul": 7,
            "Aug": 8,
            "Sep": 9,
            "Oct": 10,
            "Nov": 11,
            "Dec": 12,
        }

        day, month, year = date.split()
        day = int(day[:-2])
        month = months_map[month]

        return f"{year}-{month:02d}-{day:02d}"
