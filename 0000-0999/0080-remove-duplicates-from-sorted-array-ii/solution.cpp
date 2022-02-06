/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 * Runtime: 0ms
 */

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int n = (int)nums.size();
    if (n < 3) {
      return n;
    }

    int prev = nums[0];
    int count = 1;
    int skips = 0;

    for (int i = 1; i < n; ++i) {
      if (nums[i] == prev) {
        ++count;
      } else {
        prev = nums[i];
        count = 1;
      }

      nums[i - skips] = nums[i];

      if (count > 2) {
        ++skips;
      }
    }

    return n - skips;
  }
};
