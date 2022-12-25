/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-subsequence-with-limited-sum/
 * Runtime: 16ms (95.00%)
 */

class Solution {
public:
  vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
      nums[i] += nums[i - 1];
    }

    for (int& q : queries) {
      q = upper_bound(nums.begin(), nums.end(), q) - nums.begin();
    }
    return queries;
  }
};
