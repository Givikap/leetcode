using namespace std;

#include <vector>

class Solution {
public:
  int maxArea(vector<int> &height) {
    int left = 0;
    int right = height.size() - 1;

    int maxArea = 0;

    while (left < right) {
      maxArea = max(maxArea, min(height[left], height[right]) * (right - left));

      if (height[left] > height[right])
        --right;
      else
        ++left;
    }

    return maxArea;
  }
};
