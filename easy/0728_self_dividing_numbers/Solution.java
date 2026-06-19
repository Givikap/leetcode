import java.util.ArrayList;
import java.util.List;

class Solution {
  public List<Integer> selfDividingNumbers(int left, int right) {
    final List<Integer> dividingNums = new ArrayList<>();

    for (int num = left; num < right + 1; ++num) {
      int numCopy = num;
      while (numCopy != 0) {
        final int digit = numCopy % 10;

        if (digit == 0 || num % digit != 0) {
          break;
        }

        numCopy /= 10;
      }

      if (numCopy == 0) {
        dividingNums.add(num);
      }
    }

    return dividingNums;
  }
}
