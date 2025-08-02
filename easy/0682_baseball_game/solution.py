from typing import List

class Solution:
    def calPoints(self, operations: List[str]) -> int:
        stack = []

        for operation in operations:
            if operation.lstrip('-').isdigit():
                stack.append(int(operation))
            elif operation == '+':
                stack.append(stack[-1] + stack[-2])
            elif operation == 'D':
                stack.append(stack[-1] * 2)
            elif operation == 'C':
                stack.pop()

        return sum(stack)