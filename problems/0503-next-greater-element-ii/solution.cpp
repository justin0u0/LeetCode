/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/next-greater-element-ii/
 * Runtime: 12ms (97.72%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    const int n = nums.size();
    vector<int> answer(n, -1);

    stack<int> stk;
    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && nums[stk.top()] < nums[i]) {
        answer[stk.top()] = nums[i];
        stk.pop();
      }
      stk.push(i);
    }
    for (int i = 0; i < n - 1; ++i) {
      while (!stk.empty() && nums[stk.top()] < nums[i]) {
        answer[stk.top()] = nums[i];
        stk.pop();
      }
      stk.push(i);
    }
    return answer;
  }
};
