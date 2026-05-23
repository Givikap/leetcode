class Solution {
  public double largestTriangleArea(int[][] points) {
    double maxArea = 0.0;

    for (int i = 0; i < points.length; ++i) {
      for (int j = i + 1; j < points.length; ++j) {
        for (int k = j + 1; k < points.length; ++k) {
          final int x1 = points[i][0];
          final int y1 = points[i][1];

          final int x2 = points[j][0];
          final int y2 = points[j][1];

          final int x3 = points[k][0];
          final int y3 = points[k][1];

          maxArea =
              Math.max(maxArea, Math.abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
        }
      }
    }

    return maxArea;
  }
}
