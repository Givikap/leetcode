using namespace std;

#include <unordered_set>
#include <vector>

class Solution {
public:
  int countElements(vector<int> &arr) {
    unordered_set<int> numsSet(arr.begin(), arr.end());
    int elementsCount = 0;

    for (const int &num : arr) {
      if (numsSet.find(num + 1) != numsSet.end())
        elementsCount++;
    }

    return elementsCount;
  }
};
