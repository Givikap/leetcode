using namespace std;

#include <vector>

class Solution {
public:
  vector<int> luckyNumbers(vector<vector<int>> &matrix) {
    const int rows = matrix.size();
    const int cols = matrix[0].size();

    vector<int> luckyNums;

    for (vector<int> &row : matrix) {
      int rowMin = *min_element(row.begin(), row.end());
      int col = distance(row.begin(), find(row.begin(), row.end(), rowMin));

      int colMax = 0;
      for (int r = 0; r < rows; ++r)
        colMax = max(matrix[r][col], colMax);

      if (rowMin == colMax)
        luckyNums.push_back(rowMin);
    }

    return luckyNums;
  }
};
