using namespace std;

#include <vector>

class Solution {
public:
  int numSpecial(vector<vector<int>> &matrix) {
    const int rows = matrix.size();
    const int cols = matrix[0].size();

    vector<int> rowSums(rows, 0);
    vector<int> colSums(cols, 0);

    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        if (matrix[row][col] == 1) {
          rowSums[row] += matrix[row][col];
          colSums[col] += matrix[row][col];
        }
      }
    }

    int count = 0;

    for (int row = 0; row < rows; ++row) {
      if (rowSums[row] == 1) {
        for (int col = 0; col < cols; ++col) {
          if (colSums[col] == 1 && matrix[row][col] == 1)
            ++count;
        }
      }
    }

    return count;
  }
};
