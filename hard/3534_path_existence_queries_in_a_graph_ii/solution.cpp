#include <numeric>
#include <stack>
#include <unordered_set>
#include <vector>

class Solution {
public:
  std::vector<int>
  pathExistenceQueries(int n, std::vector<int> &nums, int maxDiff,
                       std::vector<std::vector<int>> &queries) {
    std::vector<size_t> sortedIndices(n);
    std::iota(sortedIndices.begin(), sortedIndices.end(), 0);
    std::sort(sortedIndices.begin(), sortedIndices.end(),
              [&](int a, int b) { return nums[a] < nums[b]; });

    std::vector<int> sortedVals(n);
    for (size_t i = 0; i < n; i++)
      sortedVals[i] = nums[sortedIndices[i]];

    std::vector<size_t> indicesMap(n);
    for (size_t i = 0; i < n; i++)
      indicesMap[sortedIndices[i]] = i;

    size_t k = (size_t)log2(n) + 1;

    std::vector<std::vector<int>> jumps(n, std::vector<int>(k, n - 1));

    for (size_t i = 0; i < n; i++) {
      auto it = upper_bound(sortedVals.begin(), sortedVals.end(),
                            sortedVals[i] + maxDiff);
      jumps[i][0] = (int)(it - sortedVals.begin()) - 1;
    }

    for (size_t j = 1; j < k; j++)
      for (size_t i = 0; i < n; i++)
        jumps[i][j] = jumps[jumps[i][j - 1]][j - 1];

    std::vector<int> pathsExist;

    for (const auto &query : queries) {
      int u = query[0], v = query[1];

      if (u == v) {
        pathsExist.push_back(0);
      } else {
        size_t start = indicesMap[u], end = indicesMap[v];
        if (start > end)
          std::swap(start, end);

        int hops = 0;

        for (int j = k - 1; j >= 0; j--) {
          if (jumps[start][j] < end) {
            start = jumps[start][j];
            hops += (1 << j);
          }
        }

        if (jumps[start][0] >= end)
          pathsExist.push_back(hops + 1);
        else
          pathsExist.push_back(-1);
      }
    }

    return pathsExist;
  }
};
