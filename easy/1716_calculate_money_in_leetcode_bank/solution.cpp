using namespace std;

class Solution {
public:
  int totalMoney(int n) {
    int weeks = (int)n / 7, days = n % 7;
    return weeks * 28 + 7 * (weeks - 1) * weeks / 2 +
           days * (2 * weeks + days + 1) / 2;
  }
};
