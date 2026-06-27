class Solution {
  public int maxIceCream(int[] costs, int coins) {
    int maxCost = costs[0];
    for (final int cost : costs) {
      maxCost = Math.max(maxCost, cost);
    }

    final int[] costsCounter = new int[maxCost + 1];
    for (final int cost : costs) {
      ++costsCounter[cost];
    }

    int coinsCopy = coins;
    int iceCreamCount = 0;

    for (int cost = 1; cost < costsCounter.length; ++cost) {
      final int count = costsCounter[cost];
      if (count == 0) {
        continue;
      }

      final int iceCreamsCost = cost * count;
      if (coinsCopy >= iceCreamsCost) {
        coinsCopy -= iceCreamsCost;
        iceCreamCount += count;
      } else {
        while (coinsCopy >= cost) {
          coinsCopy -= cost;
          ++iceCreamCount;
        }
      }
    }

    return iceCreamCount;
  }
}
