using namespace std;

#include <string>

class Solution {
public:
  string makeFancyString(string s) {
    string fancyS = "";
    fancyS.reserve(s.size());

    char prev;
    int prevCount = 0;

    for (char &c : s) {
      if (c == prev) {
        prevCount += 1;

        if (prevCount >= 3)
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
