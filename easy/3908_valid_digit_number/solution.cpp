class Solution {
public:
  bool validDigit(int n, int x) {
    bool valid = false;

    while (n > 9) {
      if (n % 10 == x)
        valid = true;

      n /= 10;
    }

    if (n == x)
      return false;

    return valid;
  }
};
