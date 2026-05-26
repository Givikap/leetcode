class Solution {
  public int numberOfSpecialChars(String word) {
    final int[] caseMap = new int[26];

    int specialCharsCount = 0;

    for (final char ch : word.toCharArray()) {
      final int chI;

      if (Character.isUpperCase(ch)) {
        chI = ch - 65;
        caseMap[chI] |= 1;
      } else {
        chI = ch - 97;
        caseMap[chI] |= 2;
      }

      if (caseMap[chI] == 3) {
        caseMap[chI] = 7;
        ++specialCharsCount;
      }
    }

    return specialCharsCount;
  }
}
