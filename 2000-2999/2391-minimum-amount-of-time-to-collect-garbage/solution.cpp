/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/
 * Runtime: 124ms (99.91%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    int answer = 0;
    int m = 0;
    int p = 0;
    int g = 0;
    int n = garbage.size();
    for (int i = garbage.size() - 1; i >= 0; --i) {
      const string& s = garbage[i];
      int t = 0;
      if (i != 0) {
        t = travel[i - 1];
      }
      for (char c : s) {
        if (c == 'M') {
          ++m;
        } else if (c == 'P') {
          ++p;
        } else {
          ++g;
        }
      }
      if (m != 0) {
        answer += t;
      }
      if (p != 0) {
        answer += t;
      }
      if (g != 0) {
        answer += t;
      }
    }
    return answer + m + p + g;
  }
};
