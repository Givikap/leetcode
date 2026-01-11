using namespace std;

#include <string>
#include <unordered_set>

class Solution {
public:
  bool isPathCrossing(string path) {
    int x = 0, y = 0;
    unordered_set<int> visited = {0};

    for (const char &direction : path) {
      switch (direction) {
      case 'N':
        ++y;
        break;
      case 'E':
        ++x;
        break;
      case 'S':
        --y;
        break;
      case 'W':
        --x;
        break;
      }

      const int hash = x * 67 + y;

      if (visited.find(hash) != visited.end())
        return true;

      visited.insert(hash);
    }

    return false;
  }
};
