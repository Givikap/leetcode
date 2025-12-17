using namespace std;

#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  bool isAlnumOrUnderscore(string s) {
    if (s.size() == 0)
      return false;

    for (char &c : s) {
      if (!isalnum(c) && c != '_')
        return false;
    }

    return true;
  }

  vector<string> validateCoupons(vector<string> &coupons,
                                 vector<string> &businessLines,
                                 vector<bool> &areActive) {
    unordered_map<string, int> validBusinessLines = {
        {"electronics", 0}, {"grocery", 1}, {"pharmacy", 2}, {"restaurant", 3}};

    vector<pair<int, string>> validCouponsItems;
    vector<string> validCoupons;

    for (int i = 0; i < coupons.size(); ++i) {
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
