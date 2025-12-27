using namespace std;

#include <vector>

class Solution {
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    const int flowerbedLen = flowerbed.size();

    for (int i = 0; n && i < flowerbedLen; ++i) {
      if (flowerbed[i] == 0 && (i - 1 == -1 || flowerbed[i - 1] == 0) &&
          (i + 1 == flowerbedLen || flowerbed[i + 1] == 0)) {
        flowerbed[i++] = 1;
        --n;
      }
    }

    return n == 0;
  }
};
