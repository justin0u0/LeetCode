/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/
 * Runtime: 55ms (11.55%)
 */

class Solution {
public:
  int sumCounts(const vector<int>& nums) {
    const int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      unordered_set<int> s;
      for (int j = i; j < n; ++j) {
        s.emplace(nums[j]);
        cnt += s.size() * s.size();
      }
    }
    return cnt;
  }
};
