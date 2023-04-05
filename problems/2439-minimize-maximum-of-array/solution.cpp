/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimize-maximum-of-array/
 * Runtime: 112ms (97.99%)
 */

class Solution {
public:
  int minimizeArrayValue(const vector<int>& nums) {
    int answer = 0;
    double sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      answer = max(answer, (int)ceil(sum / (i + 1)));
    }
    return answer;
  }
};
