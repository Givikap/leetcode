using namespace std;

#include <string>

class Solution {
public:
  int numberOfWays(string corridor) {
    static const int MOD = 1'000'000'007;

    int sectionStart = -1;
    int prevSectionEnd = -1;

    long numberOfWays = 1;

    for (int i = 0; i < corridor.size(); ++i) {
      if (corridor[i] != 'S')
        continue;

      if (sectionStart == -1) {
        sectionStart = i;

        if (prevSectionEnd != -1)
          numberOfWays = (numberOfWays * (sectionStart - prevSectionEnd)) % MOD;
      } else {
        prevSectionEnd = i;
        sectionStart = -1;
      }
    }

    if (sectionStart != -1 || prevSectionEnd == -1)
      return 0;

    return numberOfWays;
  }
};
