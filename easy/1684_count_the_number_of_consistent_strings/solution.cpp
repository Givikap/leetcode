using namespace std;

#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int countConsistentStrings(string allowed, vector<string> &words) {
    const unordered_set<char> allowedSet(allowed.begin(), allowed.end());

    bool consistent;
    int consistentCount = 0;

    for (const string &word : words) {
      consistent = true;

      for (const char ch : word) {
        if (allowedSet.find(ch) == allowedSet.end()) {
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
