#include <string>
#include <vector>

class Solution {
public:
  bool canReach(std::string s, int minJump, int maxJump) {
    if (s.back() != '0')
      return false;

    const size_t n = s.size();

    std::vector<bool> reachable(n, false);
    reachable[0] = true;
    std::vector<int> prefixReachableCounts(n, false);
    prefixReachableCounts[1] = 1;

    for (size_t i = 1; i < n; ++i) {
      if (s[i] == '0') {
        int low = std::max(0, (int)i - maxJump);
        int high = i - minJump + 1;

        if (high > 0 &&
            prefixReachableCounts[high] - prefixReachableCounts[low] > 0)
          reachable[i] = true;
      }

      prefixReachableCounts[i + 1] =
          prefixReachableCounts[i] + static_cast<int>(reachable[i]);
    }

    return reachable.back();
  }
};
