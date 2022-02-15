/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/single-number/
 * Runtime: 12ms
 */

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int answer = 0;
    for (const int& num : nums) {
      answer ^= num;
    }

    return answer;
  }
};
