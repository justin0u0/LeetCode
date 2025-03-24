/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-days-without-meetings/
 * Runtime: 91ms (23.30%)
 */

class Solution {
public:
  int countDays(int days, vector<vector<int>>& meetings) {
    vector<pair<int, int>> meets;
    for (const auto& m : meetings) {
      meets.push_back({m[0], 1});
      meets.push_back({m[1] + 1, -1});
    }
    sort(meets.begin(), meets.end());

    int count = 0;
    int c = 0;
    int day = 1;
    for (auto [d, m] : meets) {
      if (c == 0) {
        count += d - day;
      }
      day = d;
      c += m;
    }

    if (c == 0) {
      count += days - day + 1;
    }
    return count;
  }
};
