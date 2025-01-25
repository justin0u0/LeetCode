/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/
 * Runtime: 155ms (77.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> lexicographicallySmallestArray(const vector<int>& nums, const int limit) {
    const int n = nums.size();
    vector<int> order(n);
    for (int i = 0; i < n; ++i) {
      order[i] = i;
    }
    sort(order.begin(), order.end(), [&](int i, int j) {
      return nums[i] < nums[j];
    });

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> result(n);
    int j = 0;

    for (int i = 0; i < n; ++i) {
      pq.push(order[i]);
      if (i == n - 1 || nums[order[i + 1]] - nums[order[i]] > limit) {
        while (!pq.empty()) {
          result[pq.top()] = nums[order[j]];
          pq.pop();
          ++j;
        }
      }
    }
    return result;
  }
};
