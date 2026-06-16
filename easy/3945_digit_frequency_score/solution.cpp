class Solution {
public:
  int digitFrequencyScore(int n) {
    int score = 0;

    while (n) {
      score += n % 10;
      n /= 10;
    }

    return score;
  }
};
