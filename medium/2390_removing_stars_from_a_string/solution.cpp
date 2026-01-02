using namespace std;

#include <string>

class Solution {
public:
  string removeStars(string s) {
    string stack;

    for (const char &c : s) {
      if (c == '*')
        stack.pop_back();
      else
        stack.push_back(c);
    }

    return stack;
  }
};
