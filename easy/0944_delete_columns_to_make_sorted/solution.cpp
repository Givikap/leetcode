using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  int minDeletionSize(vector<string> &strs) {
    int deleteCount = 0;

    const int cols = strs[0].size();
    const int rows = strs.size() - 1;

    for (int col = 0; col < cols; ++col) {
      for (int row = 0; row < rows; ++row) {
        if (strs[row][col] > strs[row + 1][col]) {
          ++deleteCount;
          break;
        }
      }
    }

    return deleteCount;
  }
};
