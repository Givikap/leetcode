#include <vector>

namespace utils {

class UnionFind {
private:
  std::vector<int> parent;
  std::vector<int> rank;

public:
  UnionFind(int n) : parent(n), rank(n) {
    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }

  int find(int x) {
    if (parent[x] != x)
      parent[x] = find(parent[x]);

    return parent[x];
  }

  void merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y)
      return;

    if (rank[x] < rank[y]) {
      parent[x] = y;
      rank[y] += rank[x];
    } else {
      parent[y] = x;
      rank[x] += rank[y];
    }
  }
};

} // namespace utils
