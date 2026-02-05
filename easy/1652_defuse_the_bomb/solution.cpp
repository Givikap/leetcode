using namespace std;

#include <numeric>
#include <vector>

class Solution {
public:
  vector<int> decrypt(vector<int> &code, int k) {
    const int codeLen = code.size();

    if (k == 0)
      return vector<int>(codeLen, 0);

    vector<int> decryptedCode;

    int kSum = 0;
    int i;

    if (k > 0) {
      kSum = reduce(code.begin() + 1, code.begin() + k + 1);
      i = (k + 1) % codeLen;
    } else {
      kSum = reduce(code.end() + k, code.end());
      i = 0;
    }

    k = abs(k);

    for (int _ = 0; _ < codeLen; ++_) {
      decryptedCode.push_back(kSum);
      kSum += code[i] - code[(i - k + codeLen) % codeLen];
      i = ++i % codeLen;
    }

    return decryptedCode;
  }
};
