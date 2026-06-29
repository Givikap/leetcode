class Solution {
  public int numOfStrings(String[] patterns, String word) {
    int stringsCount = 0;

    for (final String pattern : patterns) {
      if (word.contains(pattern)) {
        ++stringsCount;
      }
    }

    return stringsCount;
  }
}
