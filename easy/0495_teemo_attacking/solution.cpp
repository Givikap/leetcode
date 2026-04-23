#include <vector>

class Solution {
public:
  int findPoisonedDuration(std::vector<int> &timeSeries, int duration) {
    timeSeries.push_back(timeSeries.back() + duration);

    int poisonedDuration = 0;

    for (size_t i = 1; i < timeSeries.size(); ++i)
      poisonedDuration += std::min(duration, timeSeries[i] - timeSeries[i - 1]);

    return poisonedDuration;
  }
};
