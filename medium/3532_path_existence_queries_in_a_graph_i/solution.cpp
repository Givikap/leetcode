#include <vector>

class Solution {
public:
  std::vector<bool>
  pathExistenceQueries(int n, std::vector<int> &nums, int maxDiff,
                       std::vector<std::vector<int>> &queries) {
    std::vector<int> groupsMap(n);
    int currGroup = 0;

    for (size_t i = 1; i < n; ++i) {
      if (nums[i] - nums[i - 1] > maxDiff)
        ++currGroup;

      groupsMap[i] = currGroup;
    }

    std::vector<bool> pathsExist;
    for (const std::vector<int> &query : queries)
      pathsExist.push_back(groupsMap[query[0]] == groupsMap[query[1]]);

    return pathsExist;
  }
};
