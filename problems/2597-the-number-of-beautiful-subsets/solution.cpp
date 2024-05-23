/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/the-number-of-beautiful-subsets/
 * Runtime: 15ms (86.15%)
 */

class Solution {
public:
  int beautifulSubsets(const vector<int>& nums, int k) {
    vector<map<int, int>> count(k);
    for (int num : nums) {
      ++count[num % k][num];
    }

    int answer = 1;
    for (int i = 0; i < k; ++i) {
      int prev = 0;
      int dp0 = 1; // number of beautiful subsets without nums[i]
      int dp1 = 0; // number of beautiful subsets with nums[i]
      for (auto [v, freq] : count[i]) {
        int next0 = dp0 + dp1;
        if (prev + k == v) {
          dp1 = dp0 * ((1 << freq) - 1);
        } else {
          dp1 = (dp0 + dp1) * ((1 << freq) - 1);
        }
        dp0 = next0;
        prev = v;
      }
      answer *= (dp0 + dp1);
    }
    return answer - 1;
  }
};
