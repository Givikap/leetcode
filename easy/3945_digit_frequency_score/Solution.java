class Solution {
  public int digitFrequencyScore(int n) {
    int nCopy = n;
    int score = 0;

    while (nCopy != 0) {
      score += nCopy % 10;
      nCopy /= 10;
    }

    return score;
  }
}
