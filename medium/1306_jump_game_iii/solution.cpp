#include <stack>
#include <vector>

class Solution {
public:
  bool canReach(std::vector<int> &arr, int start) {
    const int n = arr.size();

    std::vector<bool> visited(n, false);

    std::stack<int> s;
    s.push(start);

    while (!s.empty()) {
      const int i = s.top();
      s.pop();

      visited[i] = true;

      if (arr[i] == 0)
        return true;

      const int leftI = i + arr[i];
      const int rightI = i - arr[i];

      if (leftI < n && !visited[leftI])
        s.push(leftI);
      if (rightI > -1 && !visited[rightI])
        s.push(rightI);
    }

    return false;
  }
};
