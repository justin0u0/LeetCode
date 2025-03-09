/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/alternating-groups-ii/
 * Runtime: 40ms (99.58%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int numberOfAlternatingGroups(vector<int>& colors, int k) {
    const int n = colors.size();

    int alt = 1;
    int groups = 0;
    for (int i = 1; i < n + k - 1; ++i) {
      if (colors[i % n] != colors[(i - 1) % n]) {
        ++alt;
      } else {
        alt = 1;
      }

      if (alt >= k) {
        ++groups;
      }
    }
    return groups;
  }
};
