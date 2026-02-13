using namespace std;

#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    unordered_map<char, string> phoneKeyboard = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };

    queue<string> q;
    q.push("");

    for (int i = 0; i < digits.size(); ++i) {
      for (int _ = q.size(); _ != 0; --_) {
        for (char &ch : phoneKeyboard[digits[i]])
          q.push(q.front() + ch);

        q.pop();
      }
    }

    vector<string> combinations;
    combinations.reserve(q.size());

    while (!q.empty()) {
      combinations.push_back(q.front());
      q.pop();
    }

    return combinations;
  }
};
