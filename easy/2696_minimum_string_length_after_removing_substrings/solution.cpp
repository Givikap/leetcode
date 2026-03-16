#include <stack>
#include <string>

class Solution {
public:
  int minLength(std::string s) {
    std::stack<char> st;

    for (const char &ch : s) {
      if (!st.empty() && abs(st.top() - ch) == 32)
        st.pop();
      else
        st.push(ch);
    }

    return (int)st.size();
  }
};
