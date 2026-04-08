/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/xor-after-range-multiplication-queries-i/
 * Runtime: 77ms (37.32%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  int xorAfterQueries(vector<int>& nums, const vector<vector<int>>& queries) {
    for (const auto& query : queries) {
      for (int i = query[0]; i <= query[1]; i += query[2]) {
        nums[i] = (long long)nums[i] * query[3] % mod;
      }
    }
    int res = 0;
    for (int num : nums) {
      res ^= num;
    }
    return res;
  }
};
