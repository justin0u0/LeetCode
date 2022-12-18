/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/daily-temperatures/
 * Runtime: 191ms (97.40%)
 */

class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> answer(n, 0);
    stack<int> s;
    for (int i = n - 1; i >= 0; --i) {
      int t = temperatures[i];
      while (!s.empty() && temperatures[s.top()] <= t) {
        s.pop();
      }
      if (!s.empty()) {
        answer[i] = s.top() - i;
      }
      s.push(i);
    }
    return answer;
  }
};
