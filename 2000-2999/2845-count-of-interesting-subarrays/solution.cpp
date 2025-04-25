/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-of-interesting-subarrays/
 * Runtime: 43ms (85.25%)
 */

class Solution {
public:
  long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
    unordered_map<int, int> m;
    m.emplace(0, 1);

    int sum = 0;
    long long arrs = 0;
    for (int num : nums) {
      sum = (sum + (num % modulo == k)) % modulo;
      arrs += m[(sum - k + modulo) % modulo];
      ++m[sum];
    }
    return arrs;
  }
};
