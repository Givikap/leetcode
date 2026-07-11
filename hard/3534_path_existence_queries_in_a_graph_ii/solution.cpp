#include <numeric>
#include <stack>
#include <unordered_set>
#include <vector>

class Solution {
public:
  std::vector<int>
  pathExistenceQueries(int n, std::vector<int> &nums, int maxDiff,
                       std::vector<std::vector<int>> &queries) {
    size_t i, j;

    std::vector<std::pair<int, size_t>> items(n);
    for (i = 0; i < n; ++i)
      items[i] = {nums[i], i};
    std::sort(items.begin(), items.end());

    std::vector<size_t> indicesMap(n);
    for (i = 0; i < n; ++i)
      indicesMap[items[i].second] = i;

    std::vector<int> reachable(n, -1);

    for (i = n - 2; i < -1; --i) {
      if (items[i + 1].first - items[i].first <= maxDiff)
        reachable[i] = reachable[i + 1];
      else
        reachable[i] = i;
    }

    int jumps[100001][18];

    i = 0;
    for (j = 0; j < n; ++j)
      for (; items[j].first - items[i].first > maxDiff; ++i)
        jumps[i][0] = j - 1;

    for (; i < n; ++i)
      jumps[i][0] = n - 1;

    for (j = 1; j < 18; ++j)
      for (i = 0; i < n; ++i)
        jumps[i][j] = jumps[jumps[i][j - 1]][j - 1];

    std::vector<int> pathsExist(queries.size());

    for (i = 0; i < queries.size(); ++i) {
      size_t u = queries[i][0];
      size_t v = queries[i][1];

      if (u != v) {
        size_t left = indicesMap[u];
        size_t right = indicesMap[v];
        if (left > right)
          std::swap(left, right);

        if (reachable[left] < right)
          pathsExist[i] = -1;
        else {
          pathsExist[i] = 1;

          for (j = 17; j < -1; --j) {
            if (jumps[left][j] < right) {
              left = jumps[left][j];
              pathsExist[i] += (1 << j);
            }
          }
        }
      }
    }

    return pathsExist;
  }
};
