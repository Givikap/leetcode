#include <string>
#include <unordered_map>

class Solution {
public:
  int maxNumberOfBalloons(std::string text) {
    std::unordered_map<char, int> textCounter;

    for (const char &ch : text) {
      ++textCounter[ch];
    }

    return std::min({textCounter['b'], textCounter['a'], textCounter['l'] / 2,
                     textCounter['o'] / 2, textCounter['n']});
  }
};
