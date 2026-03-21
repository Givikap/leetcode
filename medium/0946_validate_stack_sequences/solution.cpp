#include <stack>
#include <vector>

class Solution {
public:
  bool validateStackSequences(std::vector<int> &pushed,
                              std::vector<int> &popped) {
    std::stack<int> s;

    while (!pushed.empty() && !popped.empty()) {
      while (!popped.empty() && (s.empty() || s.top() != pushed.back())) {
        s.push(popped.back());
        popped.pop_back();
      }
      while (!s.empty() && !pushed.empty() && s.top() == pushed.back()) {
        s.pop();
        pushed.pop_back();
      }
    }

    return pushed.empty() && popped.empty();
  }
};
