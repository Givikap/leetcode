package utils.java;

public class UnionFind {
  private final int[] parent;
  private final int[] rank;

  public UnionFind(int n) {
    this.parent = new int[n];
    this.rank = new int[n];

    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }

  public int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }

    return parent[x];
  }

  public void merge(int x, int y) {
    final int xParent = find(x);
    final int yParent = find(y);

    if (xParent == yParent) {
      return;
    }

    if (rank[xParent] < rank[yParent]) {
      parent[xParent] = yParent;
      rank[yParent] += rank[xParent];
    } else {
      parent[yParent] = xParent;
      rank[xParent] += rank[yParent];
    }
  }
}
