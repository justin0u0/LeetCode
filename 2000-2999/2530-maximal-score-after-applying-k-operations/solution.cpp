/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximal-score-after-applying-k-operations/
 * Runtime: 131ms (98.75%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  long long maxKelements(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for (int num : nums) {
      pq.push(num);
    }

    long long score = 0;
    while (k--) {
      const int x = pq.top();
      pq.pop();
      score += x;
      pq.push((x - 1) / 3 + 1);
    }
    return score;
  }
};
