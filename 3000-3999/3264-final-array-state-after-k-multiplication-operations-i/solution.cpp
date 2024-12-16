/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < nums.size(); ++i) {
      pq.push({nums[i], i});
    }

    while (k--) {
      auto [num, i] = pq.top();
      pq.pop();

      nums[i] = num * multiplier;
      pq.push({nums[i], i});
    }

    return nums;
  }
};
