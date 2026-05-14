class Solution {
  public int[] separateDigits(int[] nums) {
    int size = 0;
    for (final int num : nums) {
      size += Math.log10(num) + 1;
    }

    final int[] digits = new int[size];
    --size;

    for (int i = nums.length - 1; i > -1; --i) {
      int num = nums[i];

      while (num > 0) {
        digits[size] = num % 10;
        --size;
        num /= 10;
      }
    }

    return digits;
  }
}
