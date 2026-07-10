#include <queue>
#include <vector>

class MedianFinder {
private:
  std::priority_queue<int, std::vector<int>> maxHeap;
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

public:
  MedianFinder() {}

  void addNum(int num) {
    if (minHeap.empty() || (!maxHeap.empty() && num > maxHeap.top()) ||
        (!minHeap.empty() && num > minHeap.top()))
      minHeap.push(num);
    else
      maxHeap.push(num);

    if (minHeap.size() - maxHeap.size() == 2) {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    } else if (maxHeap.size() - minHeap.size() == 1) {
      minHeap.push(maxHeap.top());
      maxHeap.pop();
    }
  }

  double findMedian() {
    if ((maxHeap.size() + minHeap.size()) % 2 == 0)
      return (double)(maxHeap.top() + minHeap.top()) / 2;
    else
      return (double)minHeap.top();
  }
};
