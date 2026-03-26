#include <vector>

class Solution {
public:
  int timeRequiredToBuy(std::vector<int> &tickets, int k) {
    int time = 0;

    for (size_t i = 0; i < tickets.size(); ++i) {
      time += std::min(tickets[i], tickets[k] - (i > k));
    }

    return time;
  }
};
