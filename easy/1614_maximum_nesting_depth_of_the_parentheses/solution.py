class Solution:
    def maxDepth(self, s: str) -> int:
        depth_count = 0
        max_depth = 0

        for c in s:
            if c == "(":
                depth_count += 1

                if depth_count > max_depth:
                    max_depth = depth_count

            elif c == ")":
                depth_count -= 1

        return max_depth