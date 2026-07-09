#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int findCheapestPrice(int n, std::vector<std::vector<int>> &flights, int src,
                        int dst, int k) {
    std::unordered_map<int, std::vector<std::pair<int, int>>> flightsMap;
    for (const std::vector<int> &flight : flights)
      flightsMap[flight[0]].push_back({flight[1], flight[2]});

    if (flightsMap.find(src) == flightsMap.end())
      return -1;

    std::vector<int> froms = {src};
    std::unordered_set<int> visited;
    std::unordered_map<int, int> pricesMap = {{src, 0}};

    for (int _ = 0; _ < k; ++_) {
      std::vector<int> tos;
      visited.clear();
      auto prevPricesMap = pricesMap;

      for (const int &from : froms) {
        if (visited.find(from) != visited.end())
          continue;

        for (const auto &[to, price] : flightsMap[from]) {
          if (pricesMap.find(to) != pricesMap.end())
            pricesMap[to] =
                std::min(pricesMap[to], prevPricesMap[from] + price);
          else
            pricesMap[to] = prevPricesMap[from] + price;

          tos.push_back(to);
        }

        visited.insert(from);
      }
      froms = tos;
    }

    for (const int &from : froms) {
      for (const auto &[to, price] : flightsMap[from]) {
        if (to == dst) {
          if (pricesMap.find(to) != pricesMap.end())
            pricesMap[to] = std::min(pricesMap[to], pricesMap[from] + price);
          else
            pricesMap[to] = pricesMap[from] + price;
        }
      }
    }

    return pricesMap.find(dst) != pricesMap.end() ? pricesMap[dst] : -1;
  }
};
