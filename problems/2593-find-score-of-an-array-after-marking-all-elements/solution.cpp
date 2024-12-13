/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/
 * Runtime: 119ms (69.68%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  long long findScore(vector<int>& nums) {
    const int n = nums.size();

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; ++i) {
      pq.push({nums[i], i});
    }

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      auto [num, j] = pq.top();
      pq.pop();

      if (nums[j] != num) {
        continue;
      }
      sum += num;
      nums[max(j - 1, 0)] = -1;
      nums[min(j + 1, n - 1)] = -1;
    }
    return sum;
  }
};
