#include <string>

class Solution {
public:
  int secondsBetweenTimes(std::string startTime, std::string endTime) {
    int startHours, startMinutes, startSeconds;
    sscanf(startTime.c_str(), "%d:%d:%d", &startHours, &startMinutes,
           &startSeconds);

    int endHours, endMinutes, endSeconds;
    sscanf(endTime.c_str(), "%d:%d:%d", &startHours, &startMinutes,
           &startSeconds);

    return (3600 * (endHours - startHours) + 60 * (endMinutes - startMinutes) +
            (endSeconds - startSeconds));
  }
};
