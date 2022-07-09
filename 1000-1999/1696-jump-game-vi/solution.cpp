/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/jump-game-vi/
 * Runtime: 267ms
 * Time Complexity: O(N)
 * Description:
 * 	Let dp(i) = max{dp(j)} + nums[i], for all max(0, i - k) <= j < i.
 * 	Where dp(i) is the maximum score to get when jump from index 0 to i.
 *
 * 	Use a deque to maintain the decreasing dp(j) values in range.
 * 	Then the best(max) dp(j) is in the front of the deque.
 */

class Solution {
public:
  int maxResult(vector<int>& nums, int k) {
    deque<pair<int, int>> dq{pair{0, nums[0]}};

    for (int i = 1; i < nums.size(); ++i) {
      if (dq.front().first + k < i) {
        dq.pop_front();
      }

      int dp = dq.front().second + nums[i];
      while (!dq.empty() && dq.back().second <= dp) {
        dq.pop_back();
      }
      dq.push_back(pair{i, dp});
    }

    return dq.back().second;
  }
};
