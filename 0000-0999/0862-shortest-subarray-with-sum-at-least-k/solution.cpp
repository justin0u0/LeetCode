/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
 * Runtime: 101ms (97.24%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int shortestSubarray(const vector<int>& nums, const int k) {
    // Maintain an increasing sequence of prefix sum. For each element, find the
    // the right-most prefix sum in the sequence with an subarray sum of at
    // least `k`.
    //
    // Notice that as we are finding the shortest subarray, all prefix sum
    // until the one we found can be dropped because they will only create
    // larger subarrays after moving forward to the next element.

    long long sum = 0;
    int len = INT_MAX;
    deque<pair<long long, int>> dq; // {prefix sum, index}
    dq.push_back({0, -1});
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];

      while (!dq.empty() && sum - dq.front().first >= k) {
        len = min(len, i - dq.front().second);
        dq.pop_front();
      }

      while (!dq.empty() && dq.back().first >= sum) {
        dq.pop_back();
      }
      dq.push_back({sum, i});
    }

    if (len == INT_MAX) {
      return -1;
    }
    return len;
  }
};
