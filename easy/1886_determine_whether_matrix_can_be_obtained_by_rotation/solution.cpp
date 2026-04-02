#include <vector>

class Solution {
public:
  bool findRotation(std::vector<std::vector<int>> &matrix,
                    std::vector<std::vector<int>> &target) {
    const size_t rows = matrix.size();
    const size_t cols = matrix[0].size();

    size_t row, col;

    for (int _ = 0; _ < 4; ++_) {
      std::vector<std::vector<int>> rotatedMatrix(rows,
                                                  std::vector<int>(cols, 0));

      for (row = 0; row < rows; ++row) {
        for (col = 0; col < cols; ++col) {
          rotatedMatrix[row][col] = matrix[col][row];
        }
      }

      for (row = 0; row < rows; ++row)
        std::reverse(rotatedMatrix[row].begin(), rotatedMatrix[row].end());

      if (rotatedMatrix == target)
        return true;

      matrix = rotatedMatrix;
    }

    return false;
  }
};
