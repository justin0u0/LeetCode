/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/
 * Runtime: 102ms (34.22%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minOperations(const vector<int>& nums, const int k) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int num : nums) {
      pq.push(num);
    }

    int ops;
    for (ops = 0; pq.top() < k; ++ops) {
      long long x = pq.top();
      pq.pop();
      long long y = pq.top();
      pq.pop();
      pq.push((min(x, y) << 1) + max(x, y));
    }

    return ops;
  }
};
