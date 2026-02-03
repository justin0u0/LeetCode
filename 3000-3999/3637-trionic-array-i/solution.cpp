/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/trionic-array-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool isTrionic(const vector<int>& nums) {
    const int n = nums.size();
    int l = 0;
    while (l + 1 < n && nums[l] < nums[l + 1]) {
      ++l;
    }
    int r = n - 1;
    while (r - 1 >= 0 && nums[r - 1] < nums[r]) {
      --r;
    }
    if (l == 0 || r == n - 1 || l >= r) {
      return false;
    }
    for (int i = l; i < r; ++i) {
      if (nums[i] <= nums[i + 1]) {
        return false;
      }
    }
    return true;
  }
};
