using namespace std;

#include <vector>

class Solution {
public:
  int heightChecker(vector<int> &heights) {
    const int heightsLen = heights.size();

    vector<int> expectedHeights(heights.begin(), heights.end());
    sort(expectedHeights.begin(), expectedHeights.end());

    int mismatchedHeightsCount = 0;

    for (int i = 0; i < heightsLen; ++i) {
      if (heights[i] != expectedHeights[i])
        ++mismatchedHeightsCount;
    }

    return mismatchedHeightsCount;
  }
};
