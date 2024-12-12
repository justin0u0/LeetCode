/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/take-gifts-from-the-richest-pile/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  long long pickGifts(const vector<int>& gifts, int k) {
    priority_queue<int> pq;
    for (int g : gifts) {
      pq.push(g);
    }

    while (k--) {
      int num = pq.top();
      pq.pop();
      pq.push((int)sqrt(num));
    }

    long long sum = 0;
    while (!pq.empty()) {
      sum += pq.top();
      pq.pop();
    }
    return sum;
  }
};
