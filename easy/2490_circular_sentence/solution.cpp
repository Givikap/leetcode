using namespace std;

#include <string>

class Solution {
public:
  bool isCircularSentence(string sentence) {
    int spacePos = sentence.find(' ');

    while (spacePos != -1) {
      if (sentence[spacePos - 1] != sentence[spacePos + 1])
        return false;

      spacePos = sentence.find(' ', spacePos + 1);
    }

    return sentence[0] == sentence[sentence.size() - 1];
  }
};
