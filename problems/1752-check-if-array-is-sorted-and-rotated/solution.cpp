/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool check(const vector<int>& nums) {
    const int n = nums.size();
    if (n == 1) {
      return true;
    }

    int j = 0;
    for (int i = 1; i < n + n; ++i) {
      if (nums[i % n] < nums[(i - 1) % n]) {
        j = i;
      }
      if (i - j + 1 == n) {
        return true;
      }
    }
    return false;
  }
};
