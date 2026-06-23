import java.util.ArrayList;
import java.util.List;

class Solution {
  public int maximum69Number(int num) {
    int numCopy = num;

    final List<Integer> digits = new ArrayList<>();

    while (numCopy != 0) {
      digits.add(numCopy % 10);
      numCopy /= 10;
    }

    boolean numChanged = false;

    while (!digits.isEmpty()) {
      int digit = digits.removeLast();

      if (!numChanged && digit == 6) {
        numChanged = true;
        digit = 9;
      }

      numCopy = numCopy * 10 + digit;
    }

    return numCopy;
  }
}
