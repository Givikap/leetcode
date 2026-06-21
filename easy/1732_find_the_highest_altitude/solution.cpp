#include <vector>

class Solution {
public:
  int largestAltitude(std::vector<int> &gain) {
    int maxAltitude = 0;
    int currAltitude = 0;

    for (const int &change : gain) {
      currAltitude += change;
      maxAltitude = std::max(maxAltitude, currAltitude);
    }

    return maxAltitude;
  }
};
