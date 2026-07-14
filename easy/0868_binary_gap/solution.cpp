#include <bitset>
#include <string>

class Solution {
public:
  int binaryGap(int n) {
    std::string nBin = std::bitset<32>(n).to_string();

    size_t left = nBin.find('1');
    size_t right = left != std::string::npos ? nBin.find('1', left + 1)
                                             : std::string::npos;

    int maxGap = 0;

    while (right != std::string::npos) {
      maxGap = std::max(maxGap, static_cast<int>(right - left));

      left = right;
      right = nBin.find('1', left + 1);
    }

    return maxGap;
  }
};
