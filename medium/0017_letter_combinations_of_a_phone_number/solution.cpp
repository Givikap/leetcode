#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<std::string> letterCombinations(std::string digits) {
    std::unordered_map<char, std::string> phoneKeyboard = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };

    std::queue<std::string> q;
    q.push("");

    for (int i = 0; i < digits.size(); ++i) {
      for (int _ = q.size(); _ != 0; --_) {
        for (char &ch : phoneKeyboard[digits[i]])
          q.push(q.front() + ch);

        q.pop();
      }
    }

    std::vector<std::string> combinations;
    combinations.reserve(q.size());

    while (!q.empty()) {
      combinations.push_back(q.front());
      q.pop();
    }

    return combinations;
  }
};
