#include <deque>
#include <string>

class Solution {
public:
  std::string largestEven(std::string s) {
    std::deque<char> sDeque(s.begin(), s.end());

    while (!sDeque.empty() && sDeque.back() != '2') {
      if (sDeque.back() == '1')
        sDeque.pop_back();
      else
        sDeque.pop_front();
    }

    return std::string(sDeque.begin(), sDeque.end());
  }
};
