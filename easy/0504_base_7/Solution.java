import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
  public String convertToBase7(int num) {
    if (Math.abs(num) < 6) {
      return Integer.toString(num);
    }

    final boolean isNegative = num < 0;
    if (isNegative) {
      num  = -num;
    }

    final Deque<String> dq = new ArrayDeque<>();

    while (num != 0) {
      dq.addFirst(Integer.toString(num % 7));
      num /= 7;
    }

    if (isNegative) {
      dq.addFirst("-");
    }

    return String.join("", dq);
  }
}
