using namespace std;

#include <string>

class Solution {
public:
  char numToHex(int num) {
    if (num < 10)
      return num + '0';
    else
      return num + 'W';
  }

  string toHex(int num) {
    if (num == 0)
      return "0";

    unsigned int unsignedNum = static_cast<unsigned int>(num);
    string hexNum;

    while (unsignedNum > 0) {
      hexNum += numToHex(unsignedNum % 16);
      unsignedNum /= 16;
    }

    return string(hexNum.rbegin(), hexNum.rend());
  }
};
