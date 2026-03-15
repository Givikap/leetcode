#include "../../utils/cpp/union_find.hpp"
#include <algorithm>
#include <vector>

class Solution {
public:
  int maxStability(int n, std::vector<std::vector<int>> &edges, int k) {
    sort(edges.begin(), edges.end(),
         [](const std::vector<int> &a, const std::vector<int> &b) {
           if (a[3] != b[3])
             return a[3] > b[3];
           return a[2] > b[2];
         });

    utils::UnionFind uf(n);
    std::vector<std::vector<int>> mst;

    for (const std::vector<int> &edge : edges) {
      if (uf.find(edge[0]) != uf.find(edge[1])) {
        uf.merge(edge[0], edge[1]);
        mst.push_back(edge);
      } else if (edge[3])
        return -1;
    }

    if (mst.size() != n - 1)
      return -1;

    sort(mst.begin(), mst.end(),
         [](const std::vector<int> &a, const std::vector<int> &b) {
           if (a[3] != b[3])
             return a[3] < b[3];
           return a[2] < b[2];
         });

    for (std::vector<int> &edge : mst) {
      if (!k || edge[3])
        break;

      edge[2] *= 2;
      --k;
    }

    std::vector<std::vector<int>>::iterator minEdgeIt =
        min_element(mst.begin(), mst.end(),
                    [](const std::vector<int> &a, const std::vector<int> &b) {
                      return a[2] < b[2];
                    });

    return minEdgeIt != mst.end() ? (*minEdgeIt)[2] : -1;
  }
};
