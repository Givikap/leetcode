class Solution:
    def isValid(self, s: str) -> bool:
        brackets_map = {"(": ")", "{": "}", "[": "]"}
        stack = []

        for c in s:
            if c in brackets_map:
                stack.append(c)
            elif len(stack) > 0 and brackets_map[stack[-1]] == c:
                stack.pop()
            else:
                return False

        return len(stack) == 0
