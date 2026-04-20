class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        x = list(bin(x)[2:][::-1])
        y = list(bin(y)[2:][::-1])

        while len(x) < max(len(x), len(y)):
            x.append("0")
        while len(y) < max(len(x), len(y)):
            y.append("0")

        return sum(x[i] != y[i] for i in range(len(x)))
