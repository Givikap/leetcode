#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  bool isAlnumOrUnderscore(std::string s) {
    if (s.size() == 0)
      return false;

    for (char &c : s) {
      if (!isalnum(c) && c != '_')
        return false;
    }

    return true;
  }

  std::vector<std::string>
  validateCoupons(std::vector<std::string> &coupons,
                  std::vector<std::string> &businessLines,
                  std::vector<bool> &areActive) {
    std::unordered_map<std::string, int> validBusinessLines = {
        {"electronics", 0}, {"grocery", 1}, {"pharmacy", 2}, {"restaurant", 3}};

    std::vector<std::pair<int, std::string>> validCouponsItems;
    std::vector<std::string> validCoupons;

    for (size_t i = 0; i < coupons.size(); ++i) {
      if (!areActive[i])
        continue;
      if (validBusinessLines.find(businessLines[i]) == validBusinessLines.end())
        continue;
      if (!isAlnumOrUnderscore(coupons[i]))
        continue;

      validCouponsItems.push_back(
          {validBusinessLines[businessLines[i]], coupons[i]});
    }

    sort(validCouponsItems.begin(), validCouponsItems.end(),
         [](const auto &a, const auto &b) {
           if (a.first != b.first)
             return a.first < b.first;
           return a.second < b.second;
         });

    for (const auto &item : validCouponsItems)
      validCoupons.push_back(item.second);

    return validCoupons;
  }
};
