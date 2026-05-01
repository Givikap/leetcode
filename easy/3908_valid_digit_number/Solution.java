class Solution {
  public boolean validDigit(int n, int x) {
    int nCopy = n;
    boolean valid = false;

    while (nCopy > 9) {
      if (nCopy == x) {
        valid = true;
      }

      nCopy /= 10;
    }

    return (nCopy != x) && valid;
  }
}
