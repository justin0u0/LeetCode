/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/special-array-ii/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<bool> isArraySpecial(vector<int>& nums, const vector<vector<int>>& queries) {
    int pre = nums[0];
    nums[0] = 0;
    for (int i = 1; i < nums.size(); ++i) {
      int num = nums[i];
      nums[i] = nums[i - 1] + ((pre & 1) != (nums[i] & 1));
      pre = num;
    }

    vector<bool> result;
    result.reserve(queries.size());
    for (const auto& q : queries) {
      result.emplace_back(nums[q[1]] - nums[q[0]] == q[1] - q[0]);
    }
    return result;
  }
};
