class Solution {
public:
  int minBitFlips(int start, int goal) {
    int flips = 0;

    for (int _ = 0; _ < 32; ++_) {
      if ((start & 1) != (goal & 1))
        ++flips;

      start >>= 1;
      goal >>= 1;
    }

    return flips;
  }
};
