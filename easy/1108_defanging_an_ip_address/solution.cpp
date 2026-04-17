#include <string>

class Solution {
public:
  std::string defangIPaddr(std::string address) {
    std::string defangedAddress;

    for (const char &ch : address) {
      if (ch == '.')
        defangedAddress += "[.]";
      else
        defangedAddress.push_back(ch);
    }

    return defangedAddress;
  }
};
