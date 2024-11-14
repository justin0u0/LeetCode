/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/
 * Runtime: 19ms (97.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minimizedMaximum(int n, vector<int>& quantities) {
    int l = 1;
    int r = 1e5 + 1;
    while (l < r) {
      int mid = (l + r) >> 1;

      int sum = 0;
      for (int q : quantities) {
        sum += (q - 1) / mid + 1;
      }
      if (sum <= n) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return r;
  }
};
