#include <stack>
#include <vector>

class Solution {
public:
  bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
    std::vector<std::vector<int>> prerequisitesMap(numCourses,
                                                   std::vector<int>{});

    for (const std::vector<int> &prerequisite : prerequisites)
      prerequisitesMap[prerequisite[0]].push_back(prerequisite[1]);

    std::vector<int> visited(numCourses, 0);

    for (int start = 0; start < numCourses; ++start) {
      std::stack<int> s;
      s.push(start);

      while (!s.empty()) {
        int course = s.top();

        if (visited[course] == 0)
          visited[course] = 1;

        for (const int &prerequisite : prerequisitesMap[course]) {
          if (visited[prerequisite] == 0) {
            s.push(prerequisite);
            break;
          } else if (visited[prerequisite] == 1)
            return false;
        }

        if (s.top() == course) {
          visited[course] = 2;
          s.pop();
        }
      }
    }

    return true;
  }
};
