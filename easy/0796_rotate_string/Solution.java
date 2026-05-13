class Solution {
  public boolean rotateString(String s, String goal) {
    if (s.length() != goal.length()) {
      return false;
    }

    for (int start = 0; start < s.length(); ++start) {
      if (s.charAt(start) == goal.charAt(0)
          && s.regionMatches(start, goal, 0, s.length() - start)
          && goal.regionMatches(s.length() - start, s, 0, start)) {
        return true;
      }
    }

    return false;
  }
}
