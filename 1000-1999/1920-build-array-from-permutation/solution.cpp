/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/build-array-from-permutation/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<int> buildArray(const vector<int>& nums) {
    const int n = nums.size();
    vector<int> arrs(n);
    for (int i = 0; i < n; ++i) {
      arrs[i] = nums[nums[i]];
    }
    return arrs;
  }
};
