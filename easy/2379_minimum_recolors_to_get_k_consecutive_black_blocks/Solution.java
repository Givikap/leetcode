class Solution {
  public int minimumRecolors(String blocks, int k) {
    int blackCount = 0;

    for (int i = 0; i < k; ++i) {
      if (blocks.charAt(i) == 'B') {
        ++blackCount;
      }
    }

    int recolorsCount = k - blackCount;

    if (blocks.length() == k) {
      return recolorsCount;
    }

    for (int i = k; i < blocks.length(); ++i) {
      if (blocks.charAt(i - k) == 'B') {
        --blackCount;
      }

      if (blocks.charAt(i) == 'B') {
        ++blackCount;
      }

      recolorsCount = Math.min(recolorsCount, k - blackCount);
    }

    return recolorsCount;
  }
}
