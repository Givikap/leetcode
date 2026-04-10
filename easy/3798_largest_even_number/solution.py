from collections import deque


class Solution:
    def largestEven(self, s: str) -> str:
        s_deque = deque(s)

        while s_deque and s_deque[-1] != "2":
            if s_deque[-1] == "1":
                s_deque.pop()
            else:
                s_deque.popleft()

        return "".join(s_deque)
