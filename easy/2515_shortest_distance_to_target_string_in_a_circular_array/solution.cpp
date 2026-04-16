#include <string>
#include <vector>

class Solution {
public:
  int closestTarget(std::vector<std::string> &words, std::string target,
                    int startIndex) {
    const int wordsLen = words.size();

    int left = startIndex;
    int right = startIndex;

    for (int distance = 0; distance < wordsLen / 2 + 1; ++distance) {
      if (words[left--] == target || words[right++] == target)
        return distance;

      left = (left + wordsLen) % wordsLen;
      right %= wordsLen;
    }

    return -1;
  }
};
