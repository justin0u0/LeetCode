/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/walking-robot-simulation-ii/
 * Runtime: 20ms (86.21%)
 */

class Robot {
private:
  const inline static vector<string> dirstr{"East", "North", "West", "South"};
  const inline static vector<int> dx{1, 0, -1, 0};
  const inline static vector<int> dy{0, 1, 0, -1};
  vector<vector<int>> list;
  int steps = 0;
public:
  Robot(int width, int height) {
    int x = 0;
    int y = 0;
    int dir = 0;
    do {
      list.push_back({x, y, dir});
      int x2 = x + dx[dir];
      int y2 = y + dy[dir];
      if (x2 < 0 || x2 >= width || y2 < 0 || y2 >= height) {
        dir = (dir + 1) & 3;
        x += dx[dir];
        y += dy[dir];
      } else {
        x = x2;
        y = y2;
      }
    } while (x != 0 || y != 0);
    list.front()[2] = 3;
  }
  
  void step(int num) {
    steps += num;
  }
  
  vector<int> getPos() {
    return {list[steps % list.size()][0], list[steps % list.size()][1]};
  }
  
  string getDir() {
    if (steps == 0) {
      return "East";
    }
    return dirstr[list[steps % list.size()][2]];
  }
};
