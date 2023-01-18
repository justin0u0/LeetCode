/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-sum-circular-subarray/
 * Runtime: 95ms (40.39%)
 */

class Solution {
public:
  int maxSubarraySumCircular(vector<int>& nums) {
    deque<pair<int, int>> dq{pair{-1, 0}};

    int n = nums.size();
    int sum = 0;
    int answer = INT_MIN;
    for (int i = 0; i < 2 * n; ++i) {
      while (i - dq.front().first > n) {
        dq.pop_front();
      }

      sum += nums[i % n];
      answer = max(answer, sum - dq.front().second);
      while (!dq.empty() && dq.back().second > sum) {
        dq.pop_back();
      }
      dq.push_back(pair{i, sum});
    }

    return answer;
  }
};
