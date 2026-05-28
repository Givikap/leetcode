#include <string>

class Solution {
public:
  int minimumRecolors(std::string blocks, int k) {
    int blackCount = 0;

    for (size_t i = 0; i < k; ++i) {
      if (blocks[i] == 'B')
        ++blackCount;
    }

    int recolorsCount = k - blackCount;

    if (blocks.size() == k)
      return recolorsCount;

    for (size_t i = k; i < blocks.size(); ++i) {
      if (blocks[i - k] == 'B')
        --blackCount;

      if (blocks[i] == 'B')
        ++blackCount;

      recolorsCount = std::min(recolorsCount, k - blackCount);
    }

    return recolorsCount;
  }
};
