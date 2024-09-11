/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/walking-robot-simulation/
 * Runtime: 60ms (90.85%)
 */

class Solution {
private:
  inline unsigned int hash(const unsigned int x, const unsigned int y) {
    return ((x + 32768) << 16) + (y + 32768);
  }
public:
  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    unordered_set<unsigned int> s;
    for (const auto& o : obstacles) {
      s.emplace(hash(o[0], o[1]));
    }

    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};
    int d = 0;
    int x = 0;
    int y = 0;
    int maxDist = 0;
    for (int c : commands) {
      if (c == -2) {
        d = (d + 3) % 4;
      } else if (c == -1) {
        d = (d + 1) % 4;
      } else {
        for (int i = 0; i < c; ++i) {
          int x2 = x + dx[d];
          int y2 = y + dy[d];
          if (s.find(hash(x2, y2)) != s.end()) {
            break;
          }
          x = x2;
          y = y2;
        }
        maxDist = max(maxDist, x * x + y * y);
      }
    }

    return maxDist;
  }
};
