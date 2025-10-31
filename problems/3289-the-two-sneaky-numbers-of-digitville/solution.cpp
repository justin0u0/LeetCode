/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<int> getSneakyNumbers(const vector<int>& nums) {
    vector<int> res;
    int count[101];
    for (int num : nums) {
      if (++count[num] == 2) {
        res.emplace_back(num);
      }
    }
    return res;
  }
};
