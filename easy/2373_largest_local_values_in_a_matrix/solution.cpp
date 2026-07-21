#include <vector>

class Solution {
public:
  std::vector<std::vector<int>>
  largestLocal(std::vector<std::vector<int>> &grid) {
    size_t n = grid.size();

    std::vector<std::vector<int>> maxLocal(n - 2, std::vector<int>(n - 2, 0));

    for (size_t i = 0; i < n - 2; ++i) {
      for (size_t j = 0; j < n - 2; ++j) {
        maxLocal[i][j] = std::max({
            grid[i][j],
            grid[i][j + 1],
            grid[i][j + 2],
            grid[i + 1][j],
            grid[i + 1][j + 1],
            grid[i + 1][j + 2],
            grid[i + 2][j],
            grid[i + 2][j + 1],
            grid[i + 2][j + 2],
        });
      }
    }

    return maxLocal;
  }
};
