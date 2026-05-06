class Solution {
  public String largestOddNumber(String num) {
    int lastOdd = 0;

    for (int i = 0; i < num.length(); ++i) {
      if ((num.charAt(i) - 48) % 2 == 1) {
        lastOdd = i + 1;
      }
    }

    return num.substring(0, lastOdd);
  }
}
