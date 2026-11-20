/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximize-consecutive-elements-in-an-array-after-modification/
 * Runtime: 63ms (83.49%)
 */

class Solution {
public:
  int maxSelectedElements(vector<int>& nums) {
    ranges::sort(nums);

    vector<int> arr;
    arr.reserve(nums.size() * 2);
    for (int num : nums) {
      arr.emplace_back(num + 1);
      arr.emplace_back(num);
    }

    int res = 0;
    vector<int> dp(nums.back() + 2, 0);
    for (int num : arr) {
      dp[num] = max(dp[num], dp[num - 1] + 1);
      res = max(res, dp[num]);
    }
    return res;
  }
};
