using namespace std;

#include <vector>

class Solution {
public:
  int countNegatives(vector<vector<int>> &grid) {
    const int cols = grid[0].size();

    int left, right, mid;
    int negativesCount = 0;

    for (const vector<int> &row : grid) {
      left = 0;
      right = cols - 1;

      while (left <= right) {
        mid = left + (right - left) / 2;

        if (row[mid] < 0 && (mid == 0 or row[mid - 1] >= 0)) {
          negativesCount += cols - mid;
          break;
        } else if (row[mid] < 0) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }
    }

    return negativesCount;
  }
};
