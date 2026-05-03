class Solution {
  public int[] countOppositeParity(int[] nums) {
    final int[] parities = new int[nums.length];

    int even = 0;
    int odd = 0;

    for (int i = nums.length - 1; i > -1; --i) {
      if (nums[i] % 2 == 0) {
        parities[i] = odd;
        ++even;
      } else {
        parities[i] = even;
        ++odd;
      }
    }

    return parities;
  }
}
