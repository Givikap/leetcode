using namespace std;

bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    unsigned int left = 1;
    unsigned int right = n;

    unsigned int mid;
    bool isBad;

    while (left <= right) {
      mid = (left + right) / 2;

      isBad = isBadVersion(mid);

      if (isBad && !isBadVersion(mid - 1))
        return mid;

      if (!isBad)
        left = mid + 1;
      else
        right = mid - 1;
    }

    return -1;
  }
};
