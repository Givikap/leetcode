#include <string>
#include <unordered_map>

class Solution {
public:
  char findTheDifference(std::string s, std::string t) {
    char diff = 0;

    for (const char &c : s)
      diff ^= c;

    for (const char &c : t)
      diff ^= c;

    return diff;
  }
};
