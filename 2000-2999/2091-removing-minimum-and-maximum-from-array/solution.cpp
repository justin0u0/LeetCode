/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minimumDeletions(const vector<int>& nums) {
    const int n = nums.size();

    int lo = INT_MAX;
    int hi = INT_MIN;
    int l, h;
    for (const auto [i, num] : nums | views::enumerate) {
      if (num < lo) {
        lo = num;
        l = i;
      }
      if (num > hi) {
        hi = num;
        h = i;
      }
    }

    if (l > h) {
      swap(l, h);
    }

    return min({h + 1, n - l, l + 1 + n - h});
  }
};
