class Solution {
  public int numberOfSubstrings(String s) {
    final int[] lastAbcMap = {-1, -1, -1};
    int substringsCount = 0;

    for (int i = 0; i < s.length(); ++i) {
      lastAbcMap[s.charAt(i) - 'a'] = i;
      substringsCount += Math.min(lastAbcMap[0], Math.min(lastAbcMap[1], lastAbcMap[2])) + 1;
    }

    return substringsCount;
  }
}
