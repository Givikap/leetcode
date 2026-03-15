#include <vector>

class Solution {
public:
  std::vector<int> addToArrayForm(std::vector<int> &num, int k) {
    int i = num.size() - 1;

    int carry = 0;

    while (k || carry) {
      if (i == -1) {
        num.push_back(-1);

        for (int j = num.size() - 1; j > 0; --j)
          num[j] = num[j - 1];

        num[0] = 0;
        i = 0;
      }

      num[i] += k % 10 + carry;
      carry = num[i] / 10;
      num[i] %= 10;

      k /= 10;
      --i;
    }

    return num;
  }
};
