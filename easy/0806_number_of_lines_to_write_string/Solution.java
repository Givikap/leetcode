class Solution {
  public int[] numberOfLines(int[] widths, String s) {
    int linesCount = 1;
    int currLineWidth = 0;

    for (final char ch : s.toCharArray()) {
      final int chWidth = widths[ch - 'a'];

      if (currLineWidth + chWidth > 100) {
        ++linesCount;
        currLineWidth = chWidth;
      } else {
        currLineWidth += chWidth;
      }
    }

    return new int[] {linesCount, currLineWidth};
  }
}
