from typing import List


class Solution:
    def validateStackSequences(
        self, pushed: List[int], popped: List[int]
    ) -> bool:
        stack = []

        push_i = pop_i = 0

        while push_i < len(pushed):
            if stack and stack[-1] == popped[pop_i]:
                stack.pop()
                pop_i += 1
            else:
                stack.append(pushed[push_i])
                push_i += 1

        while stack and pop_i < len(popped) and stack[-1] == popped[pop_i]:
            stack.pop()
            pop_i += 1

        return push_i == len(pushed) and pop_i == len(popped)
