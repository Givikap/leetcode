using namespace std;

#include <vector>

class Solution {
public:
  vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
    const int rows = grid.size();
    const int cols = grid[0].size();

    const int size = rows * cols;

    vector<int> flattenShiftedGrid(size, 0);

    for (const vector<int> &row : grid) {
      for (const int &num : row)
        flattenShiftedGrid[k++ % size] = num;
    }

    vector<vector<int>> shiftedGrid(rows, vector<int>(cols, 0));

    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        shiftedGrid[row][col] = flattenShiftedGrid[row * cols + col];
      }
    }

    return shiftedGrid;
  }
};
