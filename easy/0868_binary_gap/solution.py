class Solution:
    def binaryGap(self, n: int) -> int:
        nBin = bin(n)

        left = nBin.find("1")
        right = nBin.find("1", left + 1) if left != -1 else -1

        maxGap = 0

        while right != -1:
            maxGap = max(maxGap, right - left)

            left = right
            right = nBin.find("1", left + 1)

        return maxGap
