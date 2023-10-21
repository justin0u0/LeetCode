/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/constrained-subsequence-sum/
 * Runtime: 157ms (99.18%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int constrainedSubsetSum(vector<int>& nums, int k) {
    int answer = INT_MIN;
    deque<pair<int, int>> dq;
    dq.emplace_back(0, -1);
    for (int i = 0; i < nums.size(); ++i) {
      if (i - dq.front().second > k) {
        dq.pop_front();
      }
      int val = max(nums[i], dq.front().first + nums[i]);
      answer = max(answer, val);
      while (!dq.empty() && val > dq.back().first) {
        dq.pop_back();
      }
      dq.emplace_back(val, i);
    }
    return answer;
  }
};
