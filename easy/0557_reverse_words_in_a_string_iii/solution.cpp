#include <string>

class Solution {
public:
  std::string reverseWords(std::string s) {
    int i = s.find(' ');

    std::string::iterator left = s.begin();
    std::string::iterator right;

    while (i != -1) {
      right = s.begin() + i;
      reverse(left, right);
      left = right + 1;
      i = s.find(' ', i + 1);
    }
    reverse(left, s.end());

    return s;
  }
};
