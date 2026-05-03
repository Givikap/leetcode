class Solution {
  public int[] countOppositeParity(int[] nums) {
    final int[] parities = new int[nums.length];

    for (int i = 0; i < nums.length; ++i) {
      for (int j = i + 1; j < nums.length; ++j) {
        if (nums[i] % 2 != nums[j] % 2) {
          ++parities[i];
        }
      }
    }

    return parities;
  }
}
