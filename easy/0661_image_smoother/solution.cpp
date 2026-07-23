#include <vector>

class Solution {
public:
  std::vector<std::vector<int>>
  imageSmoother(std::vector<std::vector<int>> &img) {
    const size_t rows = img.size();
    const size_t cols = img[0].size();

    std::vector<std::vector<int>> imgSmoothed(rows, std::vector<int>(cols, 0));

    for (size_t row = 0; row < rows; ++row) {
      for (size_t col = 0; col < cols; ++col) {
        int cellsSum = 0;
        int cellsCount = 0;

        for (size_t r = std::max(0, static_cast<int>(row) - 1);
             r < std::min(rows, row + 2); ++r) {
          for (size_t c = std::max(0, static_cast<int>(col) - 1);
               c < std::min(cols, col + 2); ++c) {
            cellsSum += img[r][c];
            ++cellsCount;
          }
        }

        imgSmoothed[row][col] = cellsSum / cellsCount;
      }
    }

    return imgSmoothed;
  }
};
