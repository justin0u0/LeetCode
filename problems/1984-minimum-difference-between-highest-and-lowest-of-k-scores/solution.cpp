/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
 * Runtime: 2ms (45.65%)
 */

class Solution {
public:
  int minimumDifference(vector<int>& nums, const int k) {
    sort(nums.begin(), nums.end());

    int res = INT_MAX;
    for (int i = 0; i + k - 1 < nums.size(); ++i) {
      res = min(res, nums[i + k - 1] - nums[i]);
    }
    return res;
  }
};
