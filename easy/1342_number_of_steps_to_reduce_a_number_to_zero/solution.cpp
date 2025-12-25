using namespace std;

class Solution {
public:
  int numberOfSteps(int num) {
    int stepsCount = 0;

    while (num) {
      if (num % 2 == 0)
        num /= 2;
      else
        --num;

      ++stepsCount;
    }

    return stepsCount;
  }
};
