/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-harmonious-subsequence/
 * Runtime: 47ms (17.71%)
 */

class Solution {
public:
  int findLHS(vector<int>& nums) {
    unordered_map<int, int> m;
    for (int num : nums) {
      ++m[num];
    }

    int lhs = 0;
    for (int num : nums) {
      if (m[num + 1] != 0) {
        lhs = max(lhs, m[num] + m[num + 1]);
      }
    }
    return lhs;
  }
};
