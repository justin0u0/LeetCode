/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/transformed-array/
 * Runtime: 7ms (54.87%)
 */

class Solution {
public:
  vector<int> constructTransformedArray(const vector<int>& nums) {
    const int n = nums.size();
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
      res[i] = nums[(i + nums[i] + 100 * n) % n];
    }
    return res;
  }
};
