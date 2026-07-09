#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> countSmaller(std::vector<int> &nums) {
    std::vector<int> sortedUniqueNums(nums);
    std::sort(sortedUniqueNums.begin(), sortedUniqueNums.end());
    sortedUniqueNums.erase(
        std::unique(sortedUniqueNums.begin(), sortedUniqueNums.end()),
        sortedUniqueNums.end());

    const size_t n = nums.size();
    const size_t m = sortedUniqueNums.size();

    std::unordered_map<int, size_t> rankMap;
    for (size_t i = 0; i < m; ++i)
      rankMap[sortedUniqueNums[i]] = i + 1;

    std::vector<int> fenwickTree(m + 1);

    auto update = [&](size_t i) {
      for (; i <= m; i += i & (-i))
        ++fenwickTree[i];
    };

    auto query = [&](size_t i) {
      int sum = 0;

      for (; i > 0; i -= i & (-i))
        sum += fenwickTree[i];

      return sum;
    };

    std::vector<int> counts(n);
    for (size_t i = n - 1; i < SIZE_MAX; --i) {
      size_t rank = rankMap[nums[i]];
      counts[i] = query(rank - 1);
      update(rank);
    }

    return counts;
  }
};
