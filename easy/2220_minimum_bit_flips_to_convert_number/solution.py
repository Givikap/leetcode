class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        startBin = bin(start)
        goalBin = bin(goal)

        flips = 0

        for i in range(1, min(len(startBin), len(goalBin)) - 1):
            if startBin[-i] != goalBin[-i]:
                flips += 1

        if len(startBin) > len(goalBin):
            flips += startBin[: -len(goalBin) + 2].count("1")
        else:
            flips += goalBin[: -len(startBin) + 2].count("1")

        return flips
