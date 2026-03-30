#include <set>
#include <vector>

class Solution {
public:
  std::vector<int> toggleLightBulbs(std::vector<int> &bulbs) {
    std::set<int> on;

    for (const int &bulb : bulbs) {
      if (on.find(bulb) != on.end())
        on.erase(bulb);
      else
        on.insert(bulb);
    }

    std::vector<int> bulbsOn;
    bulbsOn.reserve(on.size());
    for (const int &bulb : on)
      bulbsOn.push_back(bulb);

    return bulbsOn;
  }
};
