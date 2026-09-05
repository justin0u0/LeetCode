/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/smallest-stable-index-ii/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int firstStableIndex(const vector<int>& nums, const int k) {
    const int n = nums.size();

    vector<int> mn = nums;
    for (int i = n - 2; i >= 0; --i) {
      mn[i] = min(mn[i], mn[i + 1]);
    }

    int mx = 0;
    for (int i = 0; i < n; ++i) {
      mx = max(mx, nums[i]);
      if (mx - mn[i] <= k) {
        return i;
      }
    }
    return -1;
  }
};
