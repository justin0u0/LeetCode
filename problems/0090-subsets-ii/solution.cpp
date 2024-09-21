/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/subsets-ii/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    auto next = [&](int i) {
      int j = i + 1;
      while (j != nums.size() && nums[i] == nums[j]) {
        ++j;
      }
      return j;
    };

    vector<int> subset;
    vector<vector<int>> subsets;
    function<void(int)> dfs = [&](int i) {
      if (i == nums.size()) {
        subsets.emplace_back(subset);
        return;
      }

      for (int j = i; j < nums.size(); j = next(j)) {
        subset.emplace_back(nums[j]);
        dfs(j + 1);
        subset.pop_back();
      }
      dfs(nums.size());
    };
    dfs(0);

    return subsets;
  }
};
