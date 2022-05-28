/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/missing-number/
 * Runtime: 8ms
 */

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int n = (int)nums.size();
    int answer = n;
    for (int i = 0; i < n; ++i) {
      answer ^= i ^ nums[i];
    }

    return answer;
  }
};
