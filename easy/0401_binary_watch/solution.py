from typing import List


class Solution:
    def readBinaryWatch(self, turned_on: int) -> List[str]:
        if turned_on == 0:
            return ["0:00"]
        if turned_on > 8:
            return []

        times = []

        for hour in range(12):
            if hour.bit_count() <= turned_on:
                time = str(hour)

                for minutes in range(60):
                    if minutes.bit_count() == turned_on - hour.bit_count():
                        times.append(f"{time}:{minutes:02d}")

        return times
