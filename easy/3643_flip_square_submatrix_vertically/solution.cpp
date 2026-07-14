#include <vector>

class Solution {
public:
  std::vector<std::vector<int>>
  reverseSubmatrix(std::vector<std::vector<int>> &grid, int x, int y, int k) {
    size_t topRow = x;
    size_t bottomRow = x + k - 1;

    while (topRow < bottomRow) {
      for (size_t col = y; col < y + k; ++col)
        std::swap(grid[topRow][col], grid[bottomRow][col]);

      ++topRow;
      --bottomRow;
    }

    return grid;
  }
};
