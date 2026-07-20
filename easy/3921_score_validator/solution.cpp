#include <string>
#include <vector>

class Solution {
public:
  std::vector<int> scoreValidator(std::vector<std::string> &events) {
    int score = 0;
    int counter = 0;

    for (const std::string &event : events) {
      if (counter == 10)
        break;

      if (event == "W")
        ++counter;
      else if (event == "WD" || event == "NB")
        ++score;
      else
        score += event[0] - '0';
    }

    return {score, counter};
  }
};
