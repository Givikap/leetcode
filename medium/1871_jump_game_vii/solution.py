class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        if s[-1] != "0":
            return False

        n = len(s)

        reachable = [False] * n
        reachable[0] = True
        prefixReachableCounts = [0] * (n + 1)
        prefixReachableCounts[1] = 1

        for i in range(1, n):
            if s[i] == "0":
                low = max(0, i - maxJump)
                high = i - minJump + 1

                if (
                    high > 0
                    and prefixReachableCounts[high]
                    - prefixReachableCounts[low]
                    > 0
                ):
                    reachable[i] = True

            prefixReachableCounts[i + 1] = prefixReachableCounts[i] + (
                1 if reachable[i] else 0
            )

        return reachable[-1]
