class Solution {
public:
  int hammingDistance(int x, int y) {
    int z = x ^ y;
    int hammingDist = 0;

    while (z) {
      hammingDist += z & 1;
      z >>= 1;
    }

    return hammingDist;
  }
};
