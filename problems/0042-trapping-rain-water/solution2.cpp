/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/trapping-rain-water/
 * Runtime: 10ms (77.49%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int trap(vector<int>& heights) {
    // Maintain decreasing sequence.
    stack<int> stk;

    int res = 0;
    for (int i = 0; i < heights.size(); ++i) {
      while (!stk.empty() && heights[i] >= heights[stk.top()]) {
        int j = stk.top();
        stk.pop();
        if (!stk.empty()) {
          res += (min(heights[stk.top()], heights[i]) - heights[j]) * (i - stk.top() - 1);
        }
      }
      stk.push(i);
    }
    return res;
  }
};
