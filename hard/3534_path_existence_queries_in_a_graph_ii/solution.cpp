#include <numeric>
#include <stack>
#include <unordered_set>
#include <vector>

class Solution {
public:
  std::vector<int>
  pathExistenceQueries(int n, std::vector<int> &nums, int maxDiff,
                       std::vector<std::vector<int>> &queries) {
    std::vector<std::pair<int, size_t>> items(n);
    for (size_t i = 0; i < n; ++i)
      items[i] = {nums[i], i};
    std::sort(items.begin(), items.end());

    std::vector<size_t> indicesMap(n);
    for (size_t i = 0; i < n; ++i)
      indicesMap[items[i].second] = i;

    int jumps[100001][18];

    size_t i = 0, j;

    for (j = 0; j < n; ++j)
      for (; items[j].first - items[i].first > maxDiff; ++i)
        jumps[i][0] = j - 1;

    for (; i < n; ++i)
      jumps[i][0] = n - 1;

    for (j = 1; j < 18; ++j)
      for (i = 0; i < n; ++i)
        jumps[i][j] = jumps[jumps[i][j - 1]][j - 1];

    std::vector<int> pathsExist(queries.size(), -1);

    for (i = 0; i < queries.size(); ++i) {
      size_t left = indicesMap[queries[i][0]];
      size_t right = indicesMap[queries[i][1]];

      if (left == right) {
        pathsExist[i] = 0;
      } else {
        if (left > right)
          std::swap(left, right);

        int hops = 0;

        for (j = 17; j < -1; --j) {
          if (jumps[left][j] < right) {
            left = jumps[left][j];
            hops += (1 << j);
          }
        }

        if (jumps[left][0] >= right)
          pathsExist[i] = hops + 1;
      }
    }

    return pathsExist;
  }
};
