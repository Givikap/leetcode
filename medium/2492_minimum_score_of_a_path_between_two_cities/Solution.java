import utils.java.UnionFind;

class Solution {
  public int minScore(int n, int[][] roads) {
    final UnionFind uf = new UnionFind(n + 1);

    for (final int[] road : roads) {
      if (uf.find(road[0]) != uf.find(road[1])) {
        uf.merge(road[0], road[1]);
      }
    }

    int minDistance = Integer.MAX_VALUE;

    for (final int[] road : roads) {
      if (uf.find(1) == uf.find(road[0])) {
        minDistance = Math.min(minDistance, road[2]);
      }
    }

    return minDistance;
  }
}
