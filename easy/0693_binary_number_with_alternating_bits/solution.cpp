using namespace std;

class Solution {
public:
  bool hasAlternatingBits(int n) {
    char curr;
    char prev = 2;

    while (n) {
      curr = n % 2;
      if (prev == curr)
        return false;

      prev = curr;
      n /= 2;
    }

    return true;
  }
};
