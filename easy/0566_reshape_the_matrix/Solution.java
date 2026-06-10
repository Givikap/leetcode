class Solution {
  public int[][] matrixReshape(int[][] mat, int r, int c) {
    final int cols = mat[0].length;

    if (r * c != mat.length * cols) {
      return mat;
    }

    final int[][] reshapedMat = new int[r][c];

    for (int i = 0; i < r * c; ++i) {
      reshapedMat[i / c][i % c] = mat[i / cols][i % cols];
    }

    return reshapedMat;
  }
}
