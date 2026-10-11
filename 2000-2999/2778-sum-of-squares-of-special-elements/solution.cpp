/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sum-of-squares-of-special-elements/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int sumOfSquares(const vector<int>& nums) {
    const int n = nums.size();
    int ans = 0;
    for (const auto [i, num] : nums | views::enumerate) {
      if (n % (i + 1) == 0) {
        ans += num * num;
      }
    }
    return ans;
  }
};
