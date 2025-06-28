/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/
 * Runtime: 2ms (50.49%)
 */

class Solution {
public:
  vector<int> maxSubsequence(vector<int>& nums, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < nums.size(); ++i) {
      pq.push({nums[i], i});
      if (i >= k) {
        pq.pop();
      }
    }

    map<int, int> m;
    while (!pq.empty()) {
      auto [num, i] = pq.top();
      pq.pop();
      m.emplace(i, num);
    }

    int i = 0;
    for (auto [_, num] : m) {
      nums[i++] = num;
    }
    nums.resize(k);
    return nums;
  }
};
