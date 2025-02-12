/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/
 * Runtime: 4ms (97.45%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maximumSum(const vector<int>& nums) {
    int maxn[82] = {0};
    int maxs = -1;

    for (int num : nums) {
      int x = num;
      int d = 0;
      while (x != 0) {
        d += x % 10;
        x /= 10;
      }

      int& n = maxn[d];
      if (n != 0) {
        maxs = max(maxs, n + num);
      }
      n = max(n, num);
    }
    return maxs;
  }
};
