#include <vector>

class Solution {
public:
  double calculateTax(std::vector<std::vector<int>> &brackets, int income) {
    double tax = 0;
    int lower = 0;

    for (const std::vector<int> &bracket : brackets) {
      int upper = bracket[0];
      int percent = bracket[1];

      int bracketIncome = std::min(upper - lower, income);
      lower = upper;

      tax += bracketIncome * percent / 100;
      income -= bracketIncome;

      if (income == 0)
        break;
    }

    return tax;
  }
};
