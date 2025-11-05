/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/
 * Runtime: 12ms (68.81%)
 */

class Solution {
public:
  vector<int> findXSum(vector<int>& nums, int k, int x) {
    unordered_map<int, int> freq;
    for (int i = 0; i < k; ++i) {
      ++freq[nums[i]];
    }

    vector<int> res;

    auto calc = [&]() {
      int sum = 0;
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      for (auto [k, v] : freq) {
        pq.push({v, k});
        sum += k * v;
        if (pq.size() > x) {
          sum -= pq.top().first * pq.top().second;
          pq.pop();
        }
      }
      res.emplace_back(sum);
    };

    for (int i = k; i < nums.size(); ++i) {
      calc();
      ++freq[nums[i]];
      --freq[nums[i - k]];
    }
    calc();

    return res;
  }
};
