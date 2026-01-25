from collections import deque
from typing import List


class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        students_queue = deque(students)
        sandwiches_queue = deque(sandwiches)

        for _ in range(len(students) * 4):
            if not students_queue:
                break

            student = students_queue.popleft()

            if sandwiches_queue[0] == student:
                sandwiches_queue.popleft()
            else:
                students_queue.append(student)

        return len(students_queue)
