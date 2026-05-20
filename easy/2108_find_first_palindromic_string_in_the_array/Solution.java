class Solution {
  public String firstPalindrome(String[] words) {
    for (final String word : words) {
      boolean isPalindrome = true;
      final int wordLen = word.length();

      for (int i = 0; i < wordLen; i++) {
        if (word.charAt(i) != word.charAt(wordLen - 1 - i)) {
          isPalindrome = false;
          break;
        }
      }

      if (isPalindrome) {
        return word;
      }
    }

    return "";
  }
}
