using namespace std;

#include "../../utils/cpp/union_find.hpp"
#include <algorithm>
#include <vector>

class Solution {
public:
  int maxStability(int n, vector<vector<int>> &edges, int k) {
    sort(edges.begin(), edges.end(),
         [](const vector<int> &a, const vector<int> &b) {
           if (a[3] != b[3])
             return a[3] > b[3];
           return a[2] > b[2];
         });

    UnionFind uf(n);
    vector<vector<int>> mst;

    for (const vector<int> &edge : edges) {
      if (uf.find(edge[0]) != uf.find(edge[1])) {
        uf.merge(edge[0], edge[1]);
        mst.push_back(edge);
      } else if (edge[3])
        return -1;
    }

    if (mst.size() != n - 1)
      return -1;

    sort(mst.begin(), mst.end(),
         [](const vector<int> &a, const vector<int> &b) {
           if (a[3] != b[3])
             return a[3] < b[3];
           return a[2] < b[2];
         });

    for (vector<int> &edge : mst) {
      if (!k || edge[3])
        break;

      edge[2] *= 2;
      --k;
    }

    vector<vector<int>>::iterator minEdgeIt = min_element(
        mst.begin(), mst.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[2] < b[2]; });

    return minEdgeIt != mst.end() ? (*minEdgeIt)[2] : -1;
  }
};
