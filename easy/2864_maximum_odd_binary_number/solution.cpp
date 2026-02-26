using namespace std;

#include <string>

class Solution {
public:
  string maximumOddBinaryNumber(string s) {
    string maxOddS;
    maxOddS.reserve(s.size());

    int onesCount = count(s.begin(), s.end(), '1');

    maxOddS.append(onesCount - 1, '1');
    maxOddS.append(s.size() - onesCount, '0');
    maxOddS.push_back('1');

    return maxOddS;
  }
};
