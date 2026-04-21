#include <string>

class Solution {
public:
  std::string licenseKeyFormatting(std::string s, int k) {
    std::string licenseKey;
    int l = 0;

    while (!s.empty()) {
      char ch = s.back();
      s.pop_back();

      if (ch == '-')
        continue;

      if (l == k) {
        licenseKey.push_back('-');
        l = 0;
      }

      licenseKey.push_back(toupper(ch));
      ++l;
    }

    std::reverse(licenseKey.begin(), licenseKey.end());
    return licenseKey;
  }
};
