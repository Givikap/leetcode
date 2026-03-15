class Solution {
public:
  int arrangeCoins(int n) {
    int row = 1;

    while (n >= row)
      n -= row++;

    return row - 1;
  }
};
