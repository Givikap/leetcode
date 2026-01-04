using namespace std;

#include <string>
#include <unordered_map>

class Solution {
public:
  int maxNumberOfBalloons(string text) {
    unordered_map<char, int> textCounter;

    for (const char &ch : text) {
      ++textCounter[ch];
    }

    return min({textCounter['b'], textCounter['a'], textCounter['l'] / 2,
                textCounter['o'] / 2, textCounter['n']});
  }
};
