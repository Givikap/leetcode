#include <vector>

class Solution {
public:
  bool areSimilar(std::vector<std::vector<int>> &mat, int k) {
    const size_t rows = mat.size();
    const size_t cols = mat[0].size();

    k %= cols;

    for (size_t row = 0; row < rows; ++row)
      for (size_t col = 0; col < cols; ++col)
        if (mat[row][col] != mat[row][(col + k) % cols])
          return false;

    return true;
  }
};
