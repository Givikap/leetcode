class Solution {
  public boolean validWordAbbreviation(String word, String abbr) {
    final int wordLen = word.length();
    final int abbrLen = abbr.length();

    int wordI = 0;
    int abbrI = 0;

    while (wordI < wordLen) {
      if (word.charAt(wordI) == abbr.charAt(abbrI)) {
        ++wordI;
        ++abbrI;
      } else if (abbr.charAt(abbrI) >= '0' && abbr.charAt(abbrI) <= '9') {
        if (abbr.charAt(abbrI) == '0') {
          return false;
        }

        int jump = 0;

        while (abbrI < abbrLen && Character.isDigit(abbr.charAt(abbrI))) {
          jump = jump * 10 + abbr.charAt(abbrI) - '0';
          ++abbrI;
        }

        wordI += jump;
      } else {
        return false;
      }
    }

    return wordI == wordLen && abbrI == abbrLen;
  }
}
