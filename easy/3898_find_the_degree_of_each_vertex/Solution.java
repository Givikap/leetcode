import java.util.Arrays;

class Solution {
  public int[] findDegrees(int[][] matrix) {
    final int[] degrees = new int[matrix.length];

    for (int i = 0; i < matrix.length; ++i) {
      degrees[i] = Arrays.stream(matrix[i]).reduce(0, (a, b) -> a + b);
    }

    return degrees;
  }
}
