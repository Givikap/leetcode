#include <string>
#include <vector>

class Solution {
public:
  std::vector<int> numberOfLines(std::vector<int> &widths, std::string s) {
    int linesCount = 1;
    int currLineWidth = 0;

    for (const char &ch : s) {
      int chWidth = widths[ch - 'a'];

      if (currLineWidth + chWidth > 100) {
        ++linesCount;
        currLineWidth = chWidth;
      } else
        currLineWidth += chWidth;
    }

    return {linesCount, currLineWidth};
  }
};
