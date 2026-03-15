#include <vector>

class Solution {
public:
  std::vector<int> luckyNumbers(std::vector<std::vector<int>> &matrix) {
    const int rows = matrix.size();
    const int cols = matrix[0].size();

    std::vector<int> luckyNums;

    for (std::vector<int> &row : matrix) {
      int rowMin = *min_element(row.begin(), row.end());
      int col = distance(row.begin(), find(row.begin(), row.end(), rowMin));

      int colMax = 0;
      for (int r = 0; r < rows; ++r)
        colMax = std::max(matrix[r][col], colMax);

      if (rowMin == colMax)
        luckyNums.push_back(rowMin);
    }

    return luckyNums;
  }
};
