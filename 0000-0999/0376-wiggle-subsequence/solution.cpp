/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/wiggle-subsequence/
 * Runtime: 3ms
 * Time Complexity: O(N)
 * Description:
 *	Greedy, determine the first difference to be positive or negative.
 *	For every number, if the difference matches, then the wiggle sequence can be increased by 1;
 *	else, replace last number in the wiggle sequence with the current number.
 */

class Solution {
private:
  inline static int solve(vector<int>& nums, bool pos) {
    int len = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if ((pos && nums[i] > nums[i - 1]) || (!pos && nums[i] < nums[i - 1])) {
        pos ^= 1;
        ++len;
      }
    }

    return len;
  }
public:
  int wiggleMaxLength(vector<int>& nums) {
    return max(solve(nums, false), solve(nums, true));
  }
};
