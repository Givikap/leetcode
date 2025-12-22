using namespace std;

#include <string>

class Solution {
public:
  string longestPalindrome(string s) {
    const int sLen = s.size();

    string longestPalindrome{s[0]};
    int left, right;

    for (int i = 0; i < sLen - 1; ++i) {
      for (int offset = 1; offset < 3; ++offset) {
        left = i;
        right = left + offset;

        if (right == sLen || s[left] != s[right])
          continue;

        for (; left > 0 && right < sLen - 1 && s[left - 1] == s[right + 1];
             --left, ++right)
          ;

        if (right - left + 1 > longestPalindrome.size())
          longestPalindrome = s.substr(left, right - left + 1);
      }
    }

    return longestPalindrome;
  }
};
