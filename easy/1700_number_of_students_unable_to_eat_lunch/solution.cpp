using namespace std;

#include <vector>

class Solution {
public:
  int countStudents(vector<int> &students, vector<int> &sandwiches) {
    vector<int> preferenceCounter(2, 0);

    for (const int &preference : students)
      ++preferenceCounter[preference];

    for (const int &sandwich : sandwiches) {
      if (preferenceCounter[sandwich]-- == 0)
        return preferenceCounter[!sandwich];
    }

    return 0;
  }
};
