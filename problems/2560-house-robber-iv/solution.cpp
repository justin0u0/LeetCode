/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/house-robber-iv/
 * Runtime: 19ms (81.98%)
 */

class Solution {
public:
  int minCapability(vector<int>& nums, int k) {
    const int n = nums.size();

    int l = 1;
    int r = *max_element(nums.begin(), nums.end()) + 1;

    while (l < r) {
      const int mid = (l + r) >> 1;

      int count = 0;
      for (int i = 0; i < n; ++i) {
        if (nums[i] <= mid) {
          ++count;
          ++i;
        }
      }
      if (count >= k) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }

    return r;
  }
};
