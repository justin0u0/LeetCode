/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-subarrays-with-score-less-than-k/
 * Runtime: 2ms (66.39%)
 */

class Solution {
public:
  long long countSubarrays(const vector<int>& nums, const long long k) {
    int j = 0;
    long long arrs = 0;
    long long sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      while (sum * (i - j + 1) >= k) {
        sum -= nums[j];
        j++;
      }
      arrs += i - j + 1;
    }
    return arrs;
  }
};
