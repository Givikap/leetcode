class Solution {
  public String reverseByType(String s) {
    final char[] chars = s.toCharArray();

    for (final boolean shouldBeLowerCase : new boolean[] {true, false}) {
      int left = 0;
      int right = s.length() - 1;

      while (true) {
        while (left < right && Character.isLowerCase(chars[left]) == shouldBeLowerCase) {
          ++left;
        }

        while (right > 0 && Character.isLowerCase(chars[right]) == shouldBeLowerCase) {
          --right;
        }

        if (left >= right) {
          break;
        }

        final char temp = chars[left];
        chars[left] = chars[right];
        chars[right] = temp;

        ++left;
        --right;
      }
    }

    return String.valueOf(chars);
  }
}
