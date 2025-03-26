/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/
 * Runtime: 45ms (48.94%)
 */

class Solution {
public:
  int minOperations(const vector<vector<int>>& grid, const int x) {
    const int n = grid.size() * grid[0].size();

    vector<int> nums;
    nums.reserve(n);
    for (const auto& row : grid) {
      for (const auto num : row) {
        nums.emplace_back(num);
      }
    }

    sort(nums.begin(), nums.end());

    int ops = 0;
    const int target = nums[n / 2];
    for (int num : nums) {
      if (abs(num - target) % x != 0) {
        return -1;
      }
      ops += abs(num - target) / x;
    }
    return ops;
  }
};
