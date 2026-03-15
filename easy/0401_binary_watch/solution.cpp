#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> readBinaryWatch(int turnedOn) {
    if (turnedOn == 0)
      return std::vector<std::string>{"0:00"};
    if (turnedOn > 8)
      return std::vector<std::string>{};

    int hour, minute;

    std::vector<std::pair<int, std::string>> hours;
    hours.reserve(12);
    for (hour = 0; hour < 12; ++hour)
      hours.push_back(std::pair<int, std::string>{__builtin_popcount(hour),
                                                  std::to_string(hour)});

    std::vector<std::pair<int, std::string>> minutes;
    minutes.reserve(60);
    for (minute = 0; minute < 60; ++minute)
      minutes.push_back(std::pair<int, std::string>{
          __builtin_popcount(minute),
          minute < 10 ? '0' + std::to_string(minute) : std::to_string(minute)});

    std::vector<std::string> times;

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
