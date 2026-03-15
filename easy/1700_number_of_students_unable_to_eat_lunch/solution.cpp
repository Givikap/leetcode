#include <vector>

class Solution {
public:
  int countStudents(std::vector<int> &students, std::vector<int> &sandwiches) {
    std::vector<int> preferenceCounter(2, 0);

    for (const int &preference : students)
      ++preferenceCounter[preference];

    for (const int &sandwich : sandwiches) {
      if (preferenceCounter[sandwich]-- == 0)
        return preferenceCounter[!sandwich];
    }

    return 0;
  }
};
