/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
 * Runtime: 4ms (98.74%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minTaps(int n, const vector<int>& ranges) {
    stack<pair<int, int>> stk;
    stk.push({-1, 0});
    for (int i = 0; i < n + 1; ++i) {
      pair<int, int> p{max(0, i - ranges[i]), min(n, i + ranges[i])};
      while (p.first <= stk.top().first && p.second > stk.top().second) {
        stk.pop();
      }
      int last = stk.top().second;
      if (p.first <= last && p.second > last) {
        p.first = last;
        stk.push(p);
      }
    }

    if (stk.size() == 1 || stk.top().second != n) {
      return -1;
    }
    return stk.size() - 1;
  }
};
