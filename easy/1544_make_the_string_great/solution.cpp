#include <string>
#include <vector>

class Solution {
public:
  std::string makeGood(std::string s) {
    std::vector<char> st;

    for (const char &ch : s) {
      if (!st.empty() && abs(st.back() - ch) == 32)
        st.pop_back();
      else
        st.push_back(ch);
    }

    return std::string(st.begin(), st.end());
  }
};
