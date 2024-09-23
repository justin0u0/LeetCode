/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/max-consecutive-ones/
 * Runtime: 23ms (84.75%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int ones = 0;
    int res = 0;
    for (int num : nums) {
      if (num == 1) {
        res = max(res, ++ones);
      } else {
        ones = 0;
      }
    }
    return res;
  }
};
