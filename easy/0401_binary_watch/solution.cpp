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

    vector<pair<int, string>> hours;
    hours.reserve(12);
    for (hour = 0; hour < 12; ++hour)
      hours.push_back(
          pair<int, string>{__builtin_popcount(hour), to_string(hour)});

    vector<pair<int, string>> minutes;
    minutes.reserve(60);
    for (minute = 0; minute < 60; ++minute)
      minutes.push_back(pair<int, string>{__builtin_popcount(minute),
                                          minute < 10 ? '0' + to_string(minute)
                                                      : to_string(minute)});

    vector<string> times;

    for (hour = 0; hour < 12; ++hour) {
      if (hours[hour].first <= turnedOn) {
        for (minute = 0; minute < 60; ++minute) {
          if (hours[hour].first + minutes[minute].first == turnedOn)
            times.push_back(hours[hour].second + ':' + minutes[minute].second);
        }
      }
    }

    return times;
  }
};
