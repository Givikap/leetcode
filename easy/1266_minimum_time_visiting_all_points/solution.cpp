using namespace std;

#include <vector>

class Solution {
public:
  int minTimeToVisitAllPoints(vector<vector<int>> &points) {
    if (points.size() == 1)
      return 0;

    int time = 0;

    int x1 = points.back()[0];
    int y1 = points.back()[1];
    points.pop_back();

    int x2, y2;

    while (!points.empty()) {
      x2 = points.back()[0];
      y2 = points.back()[1];
      points.pop_back();

      time += max(abs(x1 - x2), abs(y1 - y2));

      x1 = x2;
      y1 = y2;
    }

    return time;
  }
};
