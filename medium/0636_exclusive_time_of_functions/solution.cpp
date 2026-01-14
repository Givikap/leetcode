using namespace std;

#include <stack>
#include <string>
#include <vector>

class Solution {
public:
  vector<int> exclusiveTime(int n, vector<string> &logs) {
    stack<int> s;
    vector<int> times(n, 0);

    int lastTs;

    for (const string &log : logs) {
      int fid = stoi(log.substr(0, log.find(':')));
      char action = log.find('s') != -1 ? 's' : 'e';
      int ts = stoi(log.substr(log.rfind(':') + 1));

      if (action == 's') {
        if (!s.empty())
          times[s.top()] += ts - lastTs;

        s.push(fid);
        lastTs = ts;
      } else {
        times[s.top()] += ts - lastTs + 1;
        s.pop();

        if (!s.empty())
          lastTs = ts + 1;
      }
    }

    return times;
  }
};
