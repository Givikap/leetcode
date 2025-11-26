using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  bool validWordSquare(vector<string> &words) {
    for (int row = 0; row < words.size(); row++) {
      for (int col = 0; col < words[row].size(); col++) {
        if (col >= words.size() || row >= words[col].size() ||
            words[row][col] != words[col][row])
          return false;
      }
    }

    return true;
  }
};
