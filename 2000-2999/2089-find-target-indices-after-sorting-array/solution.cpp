/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-target-indices-after-sorting-array/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<int> targetIndices(vector<int>& nums, const int target) {
    ranges::sort(nums);
    vector<int> ans;
    for (size_t i = 0; i < nums.size(); ++i) {
      if (nums[i] == target) {
        ans.emplace_back(i);
      }
    }
    return ans;
  }
};
