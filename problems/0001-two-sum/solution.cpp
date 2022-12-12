/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/two-sum/
 * Runtime: 13ms (91.40%)
 */

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
      auto it = m.find(target - nums[i]);
      if (it != m.end()) {
        return vector<int>{i, it->second};
      }
      m.emplace(nums[i], i);
    }

    return vector<int>{};
  }
};
