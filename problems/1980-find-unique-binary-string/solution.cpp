/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-unique-binary-string/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string findDifferentBinaryString(vector<string>& nums) {
    const int n = nums.size();
    string s;
    s.reserve(n);
    for (int i = 0; i < n; ++i) {
      if (nums[i][i] == '0') {
        s += '1';
      } else {
        s += '0';
      }
    }
    return s;
  }
};
