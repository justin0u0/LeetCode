/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/
 * Runtime: 124ms (72.65%)
 */

class Solution {
private:
  vector<pair<int, int>> lines;

  bool check() {
    sort(lines.begin(), lines.end());

    int cuts = 0;

    int count = 0;
    for (auto [_, c] : lines) {
      if (count != 0 && count + c == 0) {
        ++cuts;
      }
      count += c;
    }
    return cuts >= 3;
  }
public:
  bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
    lines.clear();
    for (const auto& rect : rectangles) {
      lines.push_back({rect[0], 1});
      lines.push_back({rect[2], -1});
    }
    if (check()) {
      return true;
    }

    lines.clear();
    for (const auto& rect : rectangles) {
      lines.push_back({rect[1], 1});
      lines.push_back({rect[3], -1});
    }
    
    return check();
  }
};
