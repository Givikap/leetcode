using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  bool areAlmostEqual(string s1, string s2) {
    vector<int> difference;

    for (int i = 0; i < s1.size(); ++i) {
      if (s1[i] != s2[i])
        difference.push_back(i);
    }

    return difference.size() == 0 ||
           (difference.size() == 2 && s1[difference[0]] == s2[difference[1]] &&
            s1[difference[1]] == s2[difference[0]]);
  }
};
