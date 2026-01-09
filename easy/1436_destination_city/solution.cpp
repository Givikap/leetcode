using namespace std;

#include <unordered_map>
#include <vector>

class Solution {
public:
  string destCity(vector<vector<string>> &paths) {
    unordered_map<string, string> pathsMap;

    for (const vector<string> &path : paths)
      pathsMap[path[0]] = path[1];

    string destination = paths[0][0];

    while (pathsMap.find(destination) != pathsMap.end())
      destination = pathsMap[destination];

    return destination;
  }
};
