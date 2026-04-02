#include <vector>

class Solution {
public:
  std::vector<std::vector<int>>
  constructProductMatrix(std::vector<std::vector<int>> &grid) {
    const int rows = grid.size();
    const int cols = grid[0].size();

    std::vector<std::vector<int>> productGrid(rows, std::vector<int>(cols, 1));

    int row, col;

    long prefixProduct = 1;
    for (row = 0; row < rows; ++row) {
      for (col = 0; col < cols; ++col) {
        productGrid[row][col] = prefixProduct;
        prefixProduct = (prefixProduct * grid[row][col]) % 12345;
      }
    }

    long suffixProduct = 1;
    for (row = rows - 1; row > -1; --row) {
      for (col = cols - 1; col > -1; --col) {
        productGrid[row][col] = (productGrid[row][col] * suffixProduct) % 12345;
        suffixProduct = (suffixProduct * grid[row][col]) % 12345;
      }
    }

    return productGrid;
  }
};
