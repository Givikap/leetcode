class Solution {
  public String reverseOnlyLetters(String s) {
    final char[] sArray = s.toCharArray();

    int left = 0;
    int right = sArray.length - 1;

    while (left < right) {
      if (Character.isLetter(sArray[left]) && Character.isLetter(sArray[right])) {
        final char temp = sArray[left];
        sArray[left] = sArray[right];
        sArray[right] = temp;

        ++left;
        --right;
      } else if (Character.isLetter(sArray[left])) {
        --right;
      } else {
        ++left;
      }
    }

    return new String(sArray);
  }
}
