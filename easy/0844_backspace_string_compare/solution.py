class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def apply_backspaces(s: str) -> list[str]:
            stack = []

            for c in s:
                if c == "#":
                    if stack:
                        stack.pop()
                else:
                    stack.append(c)

            return stack

        return apply_backspaces(s) == apply_backspaces(t)