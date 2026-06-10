#include <vector>

class Solution {
public:
  std::vector<std::vector<int>>
  matrixReshape(std::vector<std::vector<int>> &mat, int r, int c) {
    const size_t cols = mat[0].size();

    if (static_cast<size_t>(r * c) != mat.size() * cols)
      return mat;

    std::vector<std::vector<int>> reshapedMat(r, std::vector<int>(c, 0));

    for (size_t i = 0; i < static_cast<size_t>(r * c); ++i)
      reshapedMat[i / c][i % c] = mat[i / cols][i % cols];

    return reshapedMat;
  }
};
