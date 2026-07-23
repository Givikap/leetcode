#include <numeric>
#include <string>

class Solution {
public:
  std::string gcdOfStrings(std::string str1, std::string str2) {
    const size_t pivot = std::gcd(str1.size(), str2.size());
    const std::string substr = str1.substr(0, pivot);

    for (const std::string &str : {str1, str2}) {
      for (size_t pos = 0; pos < str.size(); pos += pivot) {
        if (str.find(substr, pos) != pos)
          return "";
      }
    }

    return substr;
  }
};
