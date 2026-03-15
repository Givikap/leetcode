#include <unordered_map>
#include <vector>

class Solution {
public:
  std::string destCity(std::vector<std::vector<std::string>> &paths) {
    std::unordered_map<std::string, std::string> pathsMap;

    for (const std::vector<std::string> &path : paths)
      pathsMap[path[0]] = path[1];

    std::string destination = paths[0][0];

    while (pathsMap.find(destination) != pathsMap.end())
      destination = pathsMap[destination];

    return destination;
  }
};
