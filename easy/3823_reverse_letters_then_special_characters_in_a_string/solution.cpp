#include <cctype>
#include <string>

class Solution {
public:
  std::string reverseByType(std::string s) {
    const auto isLower = [](char c) {
      return std::islower(static_cast<unsigned char>(c)) != 0;
    };

    for (const bool shouldBeLowerCase : {true, false}) {
      int left = 0;
      int right = s.length() - 1;

      while (true) {
        while (left < right && isLower(s[left]) == shouldBeLowerCase)
          ++left;

        while (left < right && isLower(s[right]) == shouldBeLowerCase)
          --right;

        if (left >= right)
          break;

        std::swap(s[left++], s[right--]);
      }
    }

    return s;
  }
};
