using namespace std;

#include <set>
#include <vector>

class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    const int rows = grid.size();
    const int cols = grid[0].size();

    vector<pair<int, int>> rotten;
    int freshCount = 0;

    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        if (grid[row][col] == 2)
          rotten.push_back(pair<int, int>{row, col});
        else if (grid[row][col] == 1)
          ++freshCount;
      }
    }

    int minutes = 0;

    while (!rotten.empty() && freshCount) {
      set<pair<int, int>> toRot;

      for (const auto &[row, col] : rotten) {
        if (row > 0 && grid[row - 1][col] == 1)
          toRot.insert(pair<int, int>{row - 1, col});
        if (col + 1 < cols && grid[row][col + 1] == 1)
          toRot.insert(pair<int, int>{row, col + 1});
        if (row + 1 < rows && grid[row + 1][col] == 1)
          toRot.insert(pair<int, int>{row + 1, col});
        if (col > 0 && grid[row][col - 1] == 1)
          toRot.insert(pair<int, int>{row, col - 1});
      }

      rotten = vector<pair<int, int>>(toRot.begin(), toRot.end());
      for (const auto &[row, col] : toRot) {
        grid[row][col] = 2;
        --freshCount;
      }

      ++minutes;
    }

    return freshCount == 0 ? minutes : -1;
  }
};
