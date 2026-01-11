using namespace std;

#include <set>
#include <string>
#include <utility>

class Solution {
public:
  bool isPathCrossing(string path) {
    int x = 0, y = 0;
    set<pair<int, int>> visited;

    for (const char &direction : path) {
      visited.insert({x, y});

      if (direction == 'N')
        ++y;
      else if (direction == 'E')
        ++x;
      else if (direction == 'S')
        --y;
      else if (direction == 'W')
        --x;

      if (visited.find({x, y}) != visited.end())
        return true;
    }

    return false;
  }
};
