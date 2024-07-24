/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sort-the-jumbled-numbers/
 * Runtime: 71ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> sortJumbled(const vector<int>& mapping, const vector<int>& nums) {
    const int n = nums.size();
    vector<pair<int, int>> mapped(n);
    for (int i = 0; i < n; ++i) {
      const int x = nums[i];
      if (x == 0) {
        mapped[i] = {mapping[0], i};
      } else {
        int m = 0;
        for (int j = 1; j <= x; j *= 10) {
          m += mapping[x / j % 10] * j;
        }
        mapped[i] = {m, i};
      }
    }
    sort(mapped.begin(), mapped.end());

    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
      result[i] = nums[mapped[i].second];
    }
    return result;
  }
};
