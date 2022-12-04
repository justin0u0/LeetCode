/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-average-difference/
 * Runtime: 116ms (97.66%)
 */

class Solution {
public:
  int minimumAverageDifference(vector<int>& nums) {
    long long l = accumulate(nums.begin(), nums.end(), 0LL);
    long long r = 0;
    int n = nums.size();

    int minVal = l / n;
    int answer = n - 1;
    for (int i = n - 1; i > 0; --i) {
      l -= nums[i];
      r += nums[i];
      int val = abs((l / i) - (r / (n - i)));
      if (val <= minVal) {
        minVal = val;
        answer = i - 1;
      }
    }

    return answer;
  }
};
