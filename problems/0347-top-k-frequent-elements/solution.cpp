/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/top-k-frequent-elements/
 */

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (const int& val : nums) {
      ++freq[val];
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (const auto& it : freq) {
      if (pq.size() < k) {
        pq.emplace(it.second, it.first);
      } else if (pq.top().first < it.second) {
        pq.pop();
        pq.emplace(it.second, it.first);
      }
    }

    vector<int> answer;
    answer.reserve(pq.size());
    while (!pq.empty()) {
      answer.emplace_back(pq.top().second);
      pq.pop();
    }

    return answer;
  }
};
