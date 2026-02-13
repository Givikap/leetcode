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
    for (char &ch : phoneKeyboard[digits[0]])
      q.push(string() + ch);

    int combinationsCount;
    string combination;

    for (int i = 1; i < digits.size(); ++i) {
      combinationsCount = q.size();

      for (int _ = 0; _ < combinationsCount; ++_) {
        combination = q.front();
        q.pop();

        for (char &ch : phoneKeyboard[digits[i]])
          q.push(combination + ch);
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
