using namespace std;

#include <string>
#include <unordered_map>

class Solution {
public:
  char findTheDifference(string s, string t) {
    char diff = 0;

    for (char &c : s)
      diff ^= c;

    for (char &c : t)
      diff ^= c;

    return diff;
  }
};
