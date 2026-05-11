/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/separate-the-digits-in-an-array/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<int> separateDigits(const vector<int>& nums) {
    vector<int> res;
    for (int num : nums) {
      auto j = res.size();
      while (num > 0) {
        res.emplace_back(num % 10);
        num /= 10;
      }
      reverse(res.begin() + j, res.end());
    }
    return res;
  }
};
