/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sliding-window-maximum/
 * Runtime: 327ms
 */

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> answer;
    answer.reserve(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
      while (!dq.empty() && nums[dq.back()] < nums[i]) {
        dq.pop_back();
      }
      if (!dq.empty() && dq.front() + k == i) {
        dq.pop_front();
      }
      dq.emplace_back(i);
      if (i >= k - 1) {
        answer.emplace_back(nums[dq.front()]);
      }
    }

    return answer;
  }
};
