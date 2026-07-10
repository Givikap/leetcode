import heapq


class MedianFinder:
    def __init__(self):
        self.maxHeap = []
        self.minHeap = []

    def addNum(self, num: int) -> None:
        if (
            not self.minHeap
            or (self.maxHeap and num > -self.maxHeap[0])
            or (self.minHeap and num > self.minHeap[0])
        ):
            heapq.heappush(self.minHeap, num)
        else:
            heapq.heappush(self.maxHeap, -num)

        if len(self.minHeap) - len(self.maxHeap) == 2:
            heapq.heappush(self.maxHeap, -self.minHeap[0])
            heapq.heappop(self.minHeap)
        elif len(self.maxHeap) - len(self.minHeap) == 1:
            heapq.heappush(self.minHeap, -self.maxHeap[0])
            heapq.heappop(self.maxHeap)

    def findMedian(self) -> float:
        if (len(self.maxHeap) + len(self.minHeap)) % 2 == 0:
            return (-self.maxHeap[0] + self.minHeap[0]) / 2
        else:
            return self.minHeap[0]
