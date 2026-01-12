using namespace std;

#include <unordered_map>

class Solution {
public:
  bool confusingNumber(int n) {
    unordered_map<int, int> confusingMap = {
        {0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}};

    const int nCopy = n;
    int nRotated = 0;

    int digit;

    while (n) {
      digit = n % 10;

      n /= 10;
      nRotated *= 10;

      if (confusingMap.find(digit) != confusingMap.end())
        digit = confusingMap[digit];
      else
        return false;

      nRotated += digit;
    }

    return nCopy != nRotated;
  }
};
