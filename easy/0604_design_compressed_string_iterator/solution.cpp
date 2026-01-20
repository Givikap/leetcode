using namespace std;

#include <string>
#include <vector>

class StringIterator {
private:
  vector<pair<char, int>> encodedRuns;

public:
  StringIterator(string compressedString) {
    int prev = compressedString.size();
    int curr = prev - 1;

    while (curr >= 0) {
      while (isdigit(compressedString[curr]))
        --curr;

      encodedRuns.push_back(
          {compressedString[curr],
           stoi(compressedString.substr(curr + 1, prev - curr - 1))});

      prev = curr--;
    }
  }

  char next() {
    if (encodedRuns.size() == 0)
      return ' ';

    --encodedRuns.back().second;
    auto &[ch, count] = encodedRuns.back();

    if (count == 0)
      encodedRuns.pop_back();

    return ch;
  }

  bool hasNext() { return encodedRuns.size() > 0; }
};
