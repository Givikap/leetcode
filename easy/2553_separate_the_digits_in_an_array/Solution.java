import java.util.ArrayList;
import java.util.List;

class Solution {
  public int[] separateDigits(int[] nums) {
    final List<Integer> digits = new ArrayList<>();

    for (final Integer num : nums) {
      for (final char ch : Integer.toString(num).toCharArray()) {
        digits.add(ch - '0');
      }
    }

    return digits.stream().mapToInt(Integer::intValue).toArray();
  }
}
