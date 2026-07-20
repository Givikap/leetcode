from typing import List


class Solution:
    def scoreValidator(self, events: List[str]) -> List[int]:
        score = 0
        counter = 0

        for event in events:
            if event == "W":
                counter += 1
            elif event == "WD" or event == "NB":
                score += 1
            else:
                score += ord(event) - 48

            if counter == 10:
                break

        return [score, counter]
