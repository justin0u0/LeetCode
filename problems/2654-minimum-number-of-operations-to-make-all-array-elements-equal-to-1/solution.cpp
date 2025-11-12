/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minOperations(const vector<int>& nums) {
    const int n = nums.size();

    int ops = INT_MAX;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      int g = nums[i];
      for (int j = i + 1; j < n; ++j) {
        g = __gcd(g, nums[j]);
        if (g == 1) {
          ops = min(ops, j - i);
          break;
        }
      }
      if (nums[i] == 1) {
        ++cnt;
      }
    }
    if (cnt != 0) {
      return n - cnt;
    }
    if (ops != INT_MAX) {
      return n + ops - 1;
    }
    return -1;
  }
};
