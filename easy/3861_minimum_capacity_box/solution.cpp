#include <vector>

class Solution {
public:
  int minimumIndex(std::vector<int> &capacity, int itemSize) {
    int minI = 0;

    for (int i = 0; i < capacity.size(); ++i) {
      if (capacity[i] >= itemSize &&
          (capacity[minI] < itemSize || capacity[i] < capacity[minI]))
        minI = i;
    }

    return capacity[minI] >= itemSize ? minI : -1;
  }
};
