#include <numeric>
#include <vector>

class Solution {
public:
  std::vector<int> findDegrees(std::vector<std::vector<int>> &matrix) {
    std::vector<int> degrees;
    degrees.reserve(matrix.size());

    for (const std::vector<int> &row : matrix)
      degrees.push_back(std::reduce(row.begin(), row.end()));

    return degrees;
  }
};
