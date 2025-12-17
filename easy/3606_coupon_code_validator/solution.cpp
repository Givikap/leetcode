using namespace std;

#include <string>
#include <unordered_set>
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
    unordered_set<string> validBusinessLines(
        {"electronics", "grocery", "pharmacy", "restaurant"});

    vector<pair<string, string>> validCouponsItems;

    for (int i = 0; i < coupons.size(); ++i) {
      if (!areActive[i])
        continue;
      if (validBusinessLines.find(businessLines[i]) == validBusinessLines.end())
        continue;
      if (!isAlnumOrUnderscore(coupons[i]))
        continue;

      validCouponsItems.push_back({coupons[i], businessLines[i]});
    }

    sort(validCouponsItems.begin(), validCouponsItems.end(),
         [](const pair<string, string> &a, const pair<string, string> &b) {
           return tie(a.second, a.first) < tie(b.second, b.first);
         });

    vector<string> validCoupons;

    for (const pair<string, string> &item : validCouponsItems)
      validCoupons.push_back(item.first);

    return validCoupons;
  }
};
