using namespace std;

#include <vector>

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    const int n = nums.size();
    k = k % n;

    for (auto &[left, right] :
         vector<pair<int, int>>{{0, n - 1}, {0, k - 1}, {k, n - 1}}) {
      while (left < right)
        swap(nums[left++], nums[right--]);
    }
  }
};
