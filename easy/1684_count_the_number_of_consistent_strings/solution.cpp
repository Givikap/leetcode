#include <string>
#include <vector>

class Solution {
public:
  int countConsistentStrings(std::string allowed,
                             std::vector<std::string> &words) {
    std::vector<int> allowedHash(26, 0);

    for (const char ch : allowed)
      ++allowedHash[ch - 'a'];

    bool consistent;
    int consistentCount = 0;

    for (const std::string &word : words) {
      consistent = true;

      for (const char ch : word) {
        if (allowedHash[ch - 'a'] == 0) {
          consistent = false;
          break;
        }
      }

      if (consistent)
        ++consistentCount;
    }

    return consistentCount;
  }
};
