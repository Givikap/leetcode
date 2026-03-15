#include <numeric>
#include <vector>

class Solution {
public:
  int minimumBoxes(std::vector<int> &apples, std::vector<int> &boxes) {
    int applesCount = reduce(apples.begin(), apples.end());
    int boxesCount = 0;

    sort(boxes.begin(), boxes.end(), std::greater<int>());

    for (const int &box : boxes) {
      applesCount -= box;
      ++boxesCount;

      if (applesCount <= 0)
        break;
    }

    return boxesCount;
  }
};
