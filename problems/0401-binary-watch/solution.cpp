/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/binary-watch/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  static array<vector<string>, 11> times;
public:
  vector<string> readBinaryWatch(int turnedOn) {
    return times[turnedOn];
  }
};

array<vector<string>, 11> Solution::times = []() {
  array<vector<string>, 11> res;
  for (int h = 0; h < 12; ++h) {
    for (int m = 0; m < 60; ++m) {
      stringstream ss;
      ss << h << ':' << setfill('0') << setw(2) << m;
      string s;
      ss >> s;
      res[__builtin_popcount(h) + __builtin_popcount(m)].emplace_back(s);
    }
  }
  return res;
}();
