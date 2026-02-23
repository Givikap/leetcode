using namespace std;

#include <string>

class Solution {
public:
  string reverseWords(string s) {
    int i = s.find(' ');

    string::iterator left = s.begin();
    string::iterator right;

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
