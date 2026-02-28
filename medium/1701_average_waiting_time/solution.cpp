using namespace std;

#include <vector>

class Solution {
public:
  double averageWaitingTime(vector<vector<int>> &customers) {
    int currTime = customers[0][0];
    long waitingTime = 0;

    for (const vector<int> &customer : customers) {
      int arrival = customer[0];
      int time = customer[1];

      if (arrival > currTime)
        currTime = arrival;

      currTime += time;
      waitingTime += currTime - arrival;
    }

    return (double)waitingTime / customers.size();
  }
};
