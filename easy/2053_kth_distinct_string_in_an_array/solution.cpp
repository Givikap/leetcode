using namespace std;

#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  string kthDistinct(vector<string> &arr, int k) {
    unordered_map<string, int> stringCounter;

    for (string &s : arr)
      stringCounter[s]++;

    for (string &s : arr) {
      if (stringCounter[s] == 1 && --k == 0)
        return s;
    }

    return "";
  }
};
