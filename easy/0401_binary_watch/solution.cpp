using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  vector<string> readBinaryWatch(int turnedOn) {
    if (turnedOn == 0)
      return vector<string>{"0:00"};
    if (turnedOn > 8)
      return vector<string>{};

    int hour, minute;

    vector<int> hours(12, 0);
    for (hour = 0; hour < 12; ++hour)
      hours[hour] = __builtin_popcount(hour);

    vector<int> minutes(60, 0);
    for (minute = 0; minute < 60; ++minute)
      minutes[minute] = __builtin_popcount(minute);

    vector<string> times;

    for (hour = 0; hour < 12; ++hour) {
      if (hours[hour] <= turnedOn) {
        for (minute = 0; minute < 60; ++minute) {
          if (hours[hour] + minutes[minute] == turnedOn)
            times.push_back(
                to_string(hour) + ':' +
                (minute < 10 ? '0' + to_string(minute) : to_string(minute)));
        }
      }
    }

    return times;
  }
};
