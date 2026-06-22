#include <string>

class Solution {
public:
  std::string reverseOnlyLetters(std::string s) {
    size_t left = 0;
    size_t right = s.size() - 1;

    while (left < right) {
      if (isalpha(s[left]) && isalpha(s[right])) {
        std::swap(s[left], s[right]);
        ++left;
        --right;
      } else if (isalpha(s[left]))
        --right;
      else
        ++left;
    }

    return s;
  }
};
