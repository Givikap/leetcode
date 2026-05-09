class Solution {
  public int vowelConsonantScore(String s) {
    int vowelsCount = 0;
    int consonantsCount = 0;

    for (final char ch : s.toCharArray()) {
      if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        ++vowelsCount;
      } else if (Character.isAlphabetic(ch)) {
        ++consonantsCount;
      }
    }

    if (consonantsCount == 0) {
      return 0;
    }

    return Math.floorDiv(vowelsCount, consonantsCount);
  }
}
