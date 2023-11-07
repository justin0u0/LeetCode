/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/eliminate-maximum-number-of-monsters/
 * Runtime: 75ms (99.73%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    int n = dist.size();
    for (int i = 0; i < n; ++i) {
      dist[i] = (dist[i] - 1) / speed[i];
    }

    sort(dist.begin(), dist.end());
    int i;
    for (i = 0; i < n; ++i) {
      if (dist[i] < i) {
        return i;
      }
    }
    return n;
  }
};
