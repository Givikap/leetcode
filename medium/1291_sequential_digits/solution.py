from typing import List


class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        lowStr = str(low)

        seed = ord(lowStr[0]) - 48
        sLen = len(lowStr)

        sequentialNums = []

        while True:
            sequentialNum = 0
            for i in range(sLen):
                sequentialNum = sequentialNum * 10 + seed + i

            if sequentialNum > high:
                break
            elif seed < sequentialNum % 10 and sequentialNum >= low:
                sequentialNums.append(sequentialNum)

            if sequentialNum % 10 == 9:
                seed = 1
                sLen += 1
            else:
                seed += 1

        return sequentialNums
