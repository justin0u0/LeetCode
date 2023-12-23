/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/path-crossing/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  bool isPathCrossing(const string& path) {
    unordered_set<int> s;
    int x = 0;
    int y = 0;
    s.emplace((x << 16) + y);
    for (char dir : path) {
      switch (dir) {
      case 'N':
        --y; break;
      case 'S':
        ++y; break;
      case 'E':
        ++x; break;
      case 'W':
        --x; break;
      }
      auto [_, insert] = s.emplace((x << 16) + y);
      if (!insert) {
        return true;
      }
    }
    return false;
  }
};
