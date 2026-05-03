class Solution {
  public int[] findDegrees(int[][] matrix) {
    final int[] degrees = new int[matrix.length];

    for (int i = 0; i < matrix.length; i++) {
      for (int j = 0; j < matrix.length; j++) {
        degrees[i] += matrix[i][j];
      }
    }

    return degrees;
  }
}
