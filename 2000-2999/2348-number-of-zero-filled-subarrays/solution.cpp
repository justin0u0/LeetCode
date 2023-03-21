/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-zero-filled-subarrays/
 * Runtime: 129ms (99.40%)
 */

class Solution {
public:
  long long zeroFilledSubarray(vector<int>& nums) {
    long long answer = 0;
    int count = 0;
    for (const int num : nums) {
      if (num == 0) {
        ++count;
      } else {
        count = 0;
      }
      answer += count;
    }

    return answer;
  }
};
