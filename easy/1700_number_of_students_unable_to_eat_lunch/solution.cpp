using namespace std;

#include <unordered_map>
#include <vector>

class Solution {
public:
  int countStudents(vector<int> &students, vector<int> &sandwiches) {
    unordered_map<int, int> preferenceCounter;

    for (const int &preference : students)
      ++preferenceCounter[preference];

    for (const int &sandwich : sandwiches) {
      if (preferenceCounter[sandwich]-- == 0)
        return preferenceCounter[!sandwich];
    }

    return 0;
  }
};
