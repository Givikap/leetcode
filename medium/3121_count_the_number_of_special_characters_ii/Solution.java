import java.util.Arrays;

class Solution {
  public int numberOfSpecialChars(String word) {
    final int[] lastLowercaseMap = new int[26];
    final int[] firstUppercaseMap = new int[26];

    Arrays.fill(lastLowercaseMap, Integer.MAX_VALUE);
    Arrays.fill(firstUppercaseMap, -1);

    for (int i = 0; i < word.length(); ++i) {
      final char ch = word.charAt(i);

      if (Character.isLowerCase(ch)) {
        lastLowercaseMap[ch - 'a'] = i;
      } else if (firstUppercaseMap[ch - 'A'] == -1) {
        firstUppercaseMap[ch - 'A'] = i;
      }
    }

    int specialCharsCount = 0;

    for (int i = 0; i < 26; ++i) {
      if (lastLowercaseMap[i] < firstUppercaseMap[i]) {
        ++specialCharsCount;
      }
    }

    return specialCharsCount;
  }
}
