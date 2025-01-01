/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/house-robber-ii/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int rob(const vector<int>& nums) {
    const int n = nums.size();
    if (n == 1) {
      return nums[0];
    }
    if (n == 2) {
      return max(nums[0], nums[1]);
    }

    int dp1 = nums[1];
    int dp2 = nums[0];
    int dp3 = 0;
    for (int i = 2; i < n - 1; ++i) {
      const int d = max(dp2, dp3) + nums[i];
      dp3 = dp2;
      dp2 = dp1;
      dp1 = d;
    }

    const int res1 = max(dp1, dp2);

    dp1 = nums[2];
    dp2 = nums[1];
    dp3 = 0;
    for (int i = 3; i < n; ++i) {
      const int d = max(dp2, dp3) + nums[i];
      dp3 = dp2;
      dp2 = dp1;
      dp1 = d;
    }

    const int res2 = max(dp1, dp2);

    return max(res1, res2);
  }
};
