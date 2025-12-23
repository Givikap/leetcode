using namespace std;

#include <string>

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1)
      return s;

    const int sLen = s.size();
    const int step = 2 * numRows - 2;

    string zigzagS;

    for (int row = 0; row < numRows; ++row) {
      for (int i = row; i < sLen; i += step) {
        zigzagS.push_back(s[i]);

        if (row > 0 && row < numRows - 1 && 2 * (numRows - row - 1) + i < sLen)
          zigzagS.push_back(s[2 * (numRows - row - 1) + i]);
      }
    }

    return zigzagS;
  }
};
