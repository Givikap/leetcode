#include <string>

class Solution {
public:
  bool checkRecord(std::string s) {
    int absentCount = 0;
    int lateCount = 0;

    for (const char &record : s) {
      if (record == 'A')
        ++absentCount;

      if (record == 'L') {
        if (lateCount == 2)
          return false;
        else
          ++lateCount;
      } else
        lateCount = 0;
    }

    return absentCount < 2;
  }
};
