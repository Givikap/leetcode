class Solution {
  public int minElement(int[] nums) {
    int minReplacement = Integer.MAX_VALUE;

    for (final int num : nums) {
      int numCopy = num;
      int replacement = 0;

      while (numCopy != 0) {
        replacement += numCopy % 10;
        numCopy /= 10;
      }

      minReplacement = Math.min(minReplacement, replacement);
    }

    return minReplacement;
  }
}
