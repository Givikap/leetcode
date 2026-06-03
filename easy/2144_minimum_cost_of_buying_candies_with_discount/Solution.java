import java.util.Arrays;

class Solution {
  public int minimumCost(int[] cost) {
    Arrays.sort(cost);

    int minCost = 0;
    int i = cost.length - 1;

    while (i > 0) {
      minCost += cost[i - 1] + cost[i];
      i -= 3;
    }

    if (i == 0) {
      minCost += cost[0];
    }

    return minCost;
  }
}
