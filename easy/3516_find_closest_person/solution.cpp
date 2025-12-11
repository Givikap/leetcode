using namespace std;

#include <cstdlib>

class Solution {
public:
  int findClosest(int x, int y, int z) {
    const int xz = abs(x - z);
    const int yz = abs(y - z);

    if (xz == yz)
      return 0;
    else if (yz > xz)
      return 1;
    else
      return 2;
  }
};
