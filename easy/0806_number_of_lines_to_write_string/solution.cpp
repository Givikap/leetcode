#include <string>
#include <vector>

class Solution {
public:
  std::vector<int> numberOfLines(std::vector<int> &widths, std::string s) {
    int linesCount = 1;
    int remainingLineWidth = 100;

    for (const char &ch : s) {
      int chWidth = widths[ch - 'a'];

      if (remainingLineWidth < chWidth) {
        ++linesCount;
        remainingLineWidth = 100;
      }

      remainingLineWidth -= chWidth;
    }

    return {linesCount, 100 - remainingLineWidth};
  }
};
