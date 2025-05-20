/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/zero-array-transformation-i/
 * Runtime: 9ms (54.87%)
 */

class Solution {
private:
  int line[100005];
public:
  bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    const int n = nums.size();
    memset(line, 0, (n + 1) * sizeof(int));

    for (const auto& q : queries) {
      ++line[q[0]];
      --line[q[1] + 1];
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += line[i];
      if (sum < nums[i]) {
        return false;
      }
    }
    return true;
  }
};
