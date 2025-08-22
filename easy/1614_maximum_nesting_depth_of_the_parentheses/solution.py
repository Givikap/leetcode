class Solution:
    def maxDepth(self, s: str) -> int:
        stack = []
        maxSize = 0

        for c in s:
            if c == "(":
                stack.append("(")

                if len(stack) > maxSize:
                    maxSize = len(stack)

            elif c == ")":
                stack.pop()

        return maxSize