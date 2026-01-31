using namespace std;

#include <vector>

class Solution {
public:
  int minTimeToVisitAllPoints(vector<vector<int>> &points) {
    if (points.size() == 1)
      return 0;

    const int pointsLen = points.size();

    int x1, y1, x2, y2;
    int time = 0;

    for (int i = 0; i < pointsLen - 1; ++i) {
      x1 = points[i][0];
      y1 = points[i][1];
      x2 = points[i + 1][0];
      y2 = points[i + 1][1];

      time += max(abs(x1 - x2), abs(y1 - y2));
    }

    return time;
  }
};
