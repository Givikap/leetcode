from collections import Counter
from typing import List


class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        preference_counter = Counter(students)

        for sandwich in sandwiches:
            if preference_counter[sandwich] == 0:
                return preference_counter[not sandwich]

            preference_counter[sandwich] -= 1

        return 0
