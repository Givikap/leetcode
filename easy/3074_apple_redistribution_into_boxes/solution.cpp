using namespace std;

#include <numeric>
#include <vector>

class Solution {
public:
  int minimumBoxes(vector<int> &apples, vector<int> &boxes) {
    int applesCount = reduce(apples.begin(), apples.end());
    int boxesCount = 0;

    sort(boxes.begin(), boxes.end(), greater<int>());

    for (const int &box : boxes) {
      applesCount -= box;
      ++boxesCount;

      if (applesCount <= 0)
        break;
    }

    return boxesCount;
  }
};
