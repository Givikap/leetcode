import java.util.ArrayList;
import java.util.List;

class Solution {
  public int[] limitOccurrences(int[] nums, int k) {
    final List<Integer> limitedNums = new ArrayList<>(List.of(nums[0]));

    int count = 1;

    for (int i = 1; i < nums.length; ++i) {
      if (limitedNums.getLast() == nums[i]) {
        if (count == k) {
          continue;
        }

        ++count;
      } else {
        count = 1;
      }

      limitedNums.add(nums[i]);
    }

    final int[] limitedNumsArray = new int[limitedNums.size()];

    for (int i = 0; i < limitedNumsArray.length; ++i) {
      limitedNumsArray[i] = limitedNums.get(i);
    }

    return limitedNumsArray;
  }
}
