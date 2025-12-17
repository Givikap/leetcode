using namespace std;

#include <string>

class Solution {
public:
  string makeFancyString(string s) {
    string fancyS = "";
    fancyS.reserve(s.size());

    char prev;
    int prevCount = 0;

    for (const char &c : s) {
      if (c == prev) {
        if (++prevCount > 2)
          continue;
      } else {
        prev = c;
        prevCount = 1;
      }

      fancyS.push_back(c);
    }

    return fancyS;
  }
};
