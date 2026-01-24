using namespace std;

#include <queue>

class MovingAverage {
private:
  queue<int> q;
  int size;
  double sum;

public:
  MovingAverage(int size) : size(size), sum(0) {}

  double next(int val) {
    if (q.size() == size) {
      sum -= q.front();
      q.pop();
    }

    q.push(val);
    sum += val;

    return sum / q.size();
  }
};
