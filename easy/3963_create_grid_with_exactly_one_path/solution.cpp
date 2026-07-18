#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> createGrid(int m, int n) {
    std::vector<std::string> grid(m, std::string(n, '#'));

    for (size_t col = 0; col < n; ++col)
      grid[0][col] = '.';

    for (size_t row = 1; row < m; ++row)
      grid[row][n - 1] = '.';

    return grid;
  }
};
