#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>> &grid,
                                          int k) {
    const int rows = grid.size();
    const int cols = grid[0].size();

    const int size = rows * cols;

    std::vector<int> flattenShiftedGrid(size, 0);

    for (const std::vector<int> &row : grid) {
      for (const int &num : row)
        flattenShiftedGrid[k++ % size] = num;
    }

    std::vector<std::vector<int>> shiftedGrid(rows, std::vector<int>(cols, 0));

    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        shiftedGrid[row][col] = flattenShiftedGrid[row * cols + col];
      }
    }

    return shiftedGrid;
  }
};
