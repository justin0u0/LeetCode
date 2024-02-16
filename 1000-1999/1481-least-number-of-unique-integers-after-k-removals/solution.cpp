/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
 * Runtime: 94ms (96.18%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int findLeastNumOfUniqueInts(const vector<int>& arr, int k) {
    unordered_map<int, int> freq;
    for (int num : arr) {
      ++freq[num];
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (const auto [_, v] : freq) {
      pq.push(v);
    }

    while (!pq.empty()) {
      k -= pq.top();
      if (k < 0) {
        return pq.size();
      }
      pq.pop();
    }
    return 0;
  }
};
