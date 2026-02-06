/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-removals-to-balance-array/
 * Runtime: 24ms (94.19%)
 */

class Solution {
public:
  int minRemoval(vector<int>& nums, const long long k) {
    const int n = nums.size();
    sort(nums.begin(), nums.end());

    int res = INT_MAX;
    int j = 0;
    for (int i = 0; i < n; ++i) {
      const long long cap = k * nums[i];
      while (j < n && nums[j] <= cap) {
        ++j;
      }
      res = min(res, i + n - j);
    }

    return res;
  }
};
