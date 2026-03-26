#include <vector>

class Solution {
public:
  bool canPlaceFlowers(std::vector<int> &flowerbed, int n) {
    const size_t flowerbedLen = flowerbed.size();

    for (size_t i = 0; n && i < flowerbedLen; ++i) {
      if (flowerbed[i] == 0 && (i - 1 == -1 || flowerbed[i - 1] == 0) &&
          (i + 1 == flowerbedLen || flowerbed[i + 1] == 0)) {
        flowerbed[i++] = 1;
        --n;
      }
    }

    return n == 0;
  }
};
