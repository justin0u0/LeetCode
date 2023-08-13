/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/
 * Runtime: 89ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  bool validPartition(const vector<int>& nums) {
    bool dp[3] = {
      true,
      false,
      nums[0] == nums[1]
    };
    for (int i = 2; i < nums.size(); ++i) {
      bool next = (
        (dp[1] && nums[i] == nums[i - 1]) ||
        (dp[0] && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2]) ||
        (dp[0] && nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1)
      );
      dp[0] = dp[1];
      dp[1] = dp[2];
      dp[2] = next;
    }
    return dp[2];
  }
};
