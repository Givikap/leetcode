class Solution {
public:
  int numWaterBottles(int numBottles, int numExchanges) {
    int totalNumBottles = 0;
    int numEmptyBottles = 0;

    while (numBottles) {
      totalNumBottles += numBottles;
      numEmptyBottles += numBottles;

      numBottles = numEmptyBottles / numExchanges;
      numEmptyBottles %= numExchanges;
    }

    return totalNumBottles;
  }
};
