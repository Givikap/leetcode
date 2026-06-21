class Solution {
  public int largestAltitude(int[] gain) {
    int maxAltitude = 0;
    int currAltitude = 0;

    for (final int change : gain) {
      currAltitude += change;
      maxAltitude = Math.max(maxAltitude, currAltitude);
    }

    return maxAltitude;
  }
}
