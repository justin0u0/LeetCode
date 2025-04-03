/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/
 * Runtime: 2ms (77.44%)
 */

class Solution {
public:
  long long maximumTripletValue(vector<int>& nums) {
    int mx = 0;
    int mxd = 0;
    long long res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      res = max(res, 1LL * mxd * nums[i]);
      mxd = max(mxd, mx - nums[i]);
      mx = max(mx, nums[i]);
    }
    return res;
  }
};
