/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-special-triplets/
 * Runtime: 718ms (64.60%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  int specialTriplets(const vector<int>& nums) {
    vector<int> right(2e5 + 1, 0);
    for (int num : nums) {
      ++right[num];
    }

    vector<int> left(2e5 + 1, 0);
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      --right[nums[i]];

      const int d = nums[i] << 1;
      res = (res + 1LL * left[d] * right[d] % mod) % mod;

      ++left[nums[i]];
    }
    return res;
  }
};
