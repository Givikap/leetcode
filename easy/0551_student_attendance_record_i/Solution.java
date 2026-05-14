class Solution {
  public boolean checkRecord(String s) {
    int absentCount = 0;
    int lateCount = 0;

    for (final char record : s.toCharArray()) {
      if (record == 'A') {
        ++absentCount;
      }

      if (record == 'L') {
        if (lateCount == 2) {
          return false;
        } else {
          ++lateCount;
        }
      } else {
        lateCount = 0;
      }
    }

    return absentCount < 2;
  }
}
