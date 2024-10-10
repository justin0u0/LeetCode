/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-width-ramp/
 * Runtime: 20ms (98.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maxWidthRamp(const vector<int>& nums) {
    stack<int> stk;
    for (int i = 0; i < nums.size(); ++i) {
      if (stk.empty() || nums[stk.top()] > nums[i]) {
        stk.push(i);
      }
    }

    int answer = 0;
    for (int i = nums.size() - 1; i >= 0; --i) {
      while (!stk.empty() && nums[i] >= nums[stk.top()]) {
        answer = max(answer, i - stk.top());
        stk.pop();
      }
    }
    return answer;
  }
};
